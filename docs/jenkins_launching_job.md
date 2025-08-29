# Step-by-Step: Launching the Jenkins Job

1. Access Jenkins UI:
   1. Open your browser and go to: http://localhost:8080
2. Initial Setup
   1. If this is your first time launching Jenkins:
      1. It will ask for an admin password
         1. `sudo cat /var/lib/jenkins/secrets/initialAdminPassword` then copy the key and paste into the browser.
      2. Install recommended plugins
      3. Create an admin user
3. Create a New Pipeline Job
   1. Click “New Item”
   2. Enter a name (e.g., STM32-CI)
   3. Select “Pipeline” and click OK
4. Configure the Pipeline
   1. Option A: Use Jenkinsfile from Workspace
      1. In the job config:
        Scroll to Pipeline section.
        Set Definition to Pipeline script from SCM.
        Choose Git and enter your repo URL.
        Set the Script Path to Jenkinsfile.
   2. Option B: Paste Jenkinsfile Manually
      1. Set Definition to Pipeline script.
      2. Paste the contents of your Jenkinsfile
5. Save and Build:
   1. Click “Save”.
   2. Click “Build Now” to run the job

You’ll see the stages:
    Checkout
    Build and Flash
    Run Unit Tests
    Cleanup
    And logs from your STM32 board test output

## Install recommended plugins

Recommended Jenkins Plugins for STM32 CI with Docker

- Core essentials
  - Pipeline → required for Jenkinsfile.
  - Git → clone your repo.
  - GitHub Branch Source (if using GitHub SCM).
  - Credentials Binding → securely store SSH keys, tokens.

- For your STM32 / embedded CI
  - AnsiColor → makes console logs readable with colored Make/GCC output.
  - Timestamper → timestamps in logs, useful for debugging.
  - Warnings Next Generation → parse compiler warnings (e.g., arm-none-eabi-gcc -Wall).

- Optional modern goodies
  - Blue Ocean → modern UI for pipelines (nicer than classic view).
  - JUnit → publish test results (if later you output in JUnit XML).

### How to Install Plugins

Go to Manage Jenkins → Plugins → Available.
Search for each plugin by name.
Select and install them (you can install multiple at once).
Restart Jenkins if prompted.
