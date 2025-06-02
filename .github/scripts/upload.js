/**
 * Upload release assets script for GitHub Actions.
 *
 * This script uploads artifact files from a specified directory
 * to a GitHub Release. It is designed to be used as part of a GitHub Actions workflow.
 *
 * <b>Environment Variables</b>:
 * - `ARTIFACT_DIR`: Specifies the directory where the artifact files are stored.
 *   This variable must be set for the script to run successfully.
 *
 * Functionality:
 * - Validates the existence of the artifact directory (`ARTIFACT_DIR`).
 * - Scans the directory for files with specified extensions (`.zip` or `.tar.gz`).
 * - Uploads the filtered files as assets to the release associated with the workflow event.
 * - Logs upload status and size in megabytes for each file.
 * - Handles errors gracefully and fails the workflow if an error occurs.
 *
 * Example Usage:
 * Require the script and pass the `github-script` context and library variables.
 * <pre>
 * jobs:
 *   ...
 *   steps:
 *     ...
 *     - name: Publish release files
 *       uses: 'actions/github-script@v7'
 *       with:
 *         github-token: ${{ secrets.GITHUB_TOKEN }}
 *         script: |
 *           const upload = require('./upload.js')
 *           await upload({github, context, core})
 * </pre>
 *
 * @module upload
 *
 * @param {Object} params - The parameters provided to the script.
 * @param {Object} params.github - The GitHub API client object for interacting with GitHub.
 * @param {Object} params.context - The context object containing workflow and repository metadata.
 * @param {Object} params.core - The GitHub Actions core module for logging and error handling.
 *
 */
module.exports = async ({github, context, core}) => {
    const { promises: fs, createReadStream } = require("fs");
    const path = require('path');

    if (context.eventName !== 'release') {
        core.info(`🛑 Skipping upload: event '${context.eventName}' is not a release.`);
        return;
    }

    if (!context.payload || !context.payload.release) {
        core.setFailed('❌ No release payload found in event.');
        return;
    }

    const artifactDirectory = process.env.ARTIFACT_DIR;

    if (!artifactDirectory) {
        core.setFailed('ARTIFACT_DIR environment variable is not set.');
        return;
    }

    const extensions = ['.zip', '.tar.gz'];

    try {
        await fs.access(artifactDirectory);
        const files = await fs.readdir(artifactDirectory);
        core.debug(`📦 Found ${files.length} files in ${artifactDirectory}`);

        const uploads = files
            .filter(filename => extensions.some(extension => filename.endsWith(extension)))
            .map(async filename => {
                const filePath = path.join(artifactDirectory, filename);
                const stat = await fs.stat(filePath);
                await github.rest.repos.uploadReleaseAsset({
                    owner: context.repo.owner,
                    repo: context.repo.repo,
                    release_id: context.payload.release.id,
                    name: filename,
                    data: createReadStream(filePath),
                    headers: {
                        'content-type': 'application/octet-stream',
                        'content-length': stat.size
                    }
                });
                const megaBytes = (stat.size / (1024 * 1024)).toFixed(1);
                core.info(`✅ Uploaded: ${filename} (${megaBytes} MB)`);
            });
        await Promise.all(uploads);
    } catch (error) {
        core.setFailed(`❌ Asset upload failed: ${error.message}`);
        throw error;
    }
}
