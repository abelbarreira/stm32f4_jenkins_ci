# Jenkins

About Jenkins setup and environment.

## Environment

### On Linux Ubuntu

- `scripts\setup_linux.sh`
- `scripts\setup_python.sh`
- `scripts\setup_jenkins.sh`

### On Windows

The idea is to create an WSL Distribution with exactly the same setup.

1. Shutdown all running distributions: `wsl --shutdown`
2. Update Windows Subsystem for Linux (WSL): `wsl --update`
3. Check online distribution list: `wsl --list --online`
4. Install base distribution: `wsl --install Ubuntu-24.04 --name ubuntu-24.04-jenkins-ci`
   1. Chose username as `abr`
   2. Chose password as `abr`
   3. Log into root: `sudo su -`
   4. Disable password for sudo command: `sudo echo "abr ALL=(ALL:ALL) NOPASSWD:ALL" >> /etc/sudoers`
5. Exit from distribution: `exit`, `exit`
6. Check: `wsl --distribution ubuntu-24.04-jenkins-ci ls -laF`
7. Run distribution: `wsl --distribution ubuntu-24.04-jenkins-ci`
8. Install environment:
   1. `scripts\setup_linux.sh`
   2. `scripts\setup_python.sh`
   3. `scripts\setup_jenkins.sh`
9. Exit from distribution: `exit`

#### Export

1. Export distribution:
   1. `wsl --shutdown`
   2. `wsl --export Ubuntu-22.04 ubuntu-24.04-jenkins-ci.tar`
2. Unregister and remove the distribution: `wsl --unregister Ubuntu-22.04`

#### Import

Following steps describe how to import the distribution file `ubuntu-24.04-jenkins-ci.tar`:

- Import the distribution:
  - `wsl --set-default-version 2`
  - `wsl --import ubuntu-24.04-jenkins-ci. c:/Users/$USERNAME/AppData/Local/Packages/ubuntu-24.04-jenkins-ci ubuntu-24.04-jenkins-ci.tar --version 2`
  - `wsl --setdefault ubuntu-24.04-jenkins-ci`
- Check:
  - `wsl --shutdown`
  - `wsl --list --verbose`
  - `wsl ls -laF`

Then run distribution: `wsl --distribution ubuntu-24.04-jenkins-ci` and...

## Start Jenkins

- Start Jenkins: `sudo systemctl start jenkins` and check if it is running `sudo systemctl status jenkins`
- Open Jenkins at http://localhost:8080
- Refer to [Jenkins: Launching Jobs](jenkins_launching_job.md)
