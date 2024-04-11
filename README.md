# Prodigybuild-Testing

This repository is a part of Prodigy's Testing approach where we extensively cover all kinds of testings that applications experience before being deployed to production.

## Pre-requisites 

### Mac 
1. Homebrew: 
```shell
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```
2. Node.js: 
```shell
brew install node
```
3. MongoDB: 
```shell
brew tap mongodb/brew
brew install mongodb-community@4.2
```

### Windows
1. Chocolatey: 
```powershell
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
```
2. Node.js: 
```powershell
choco install nodejs
```
3. MongoDB: 
```powershell
choco install mongodb
```

## Installing Dependencies
Use the following command to update and install the version specific project dependencies: 
```shell
npm install
```

## Environment Setup
Depending upon your environment setup, create a `.env` file at the root of your project and update it according to your configuration. Sample `.env` file:
```
DB_HOST=localhost
DB_PORT=27017
DB_NAME=mydbname
```
## Running the Project
To run the application locally, use the following command
```shell
npm start
```

## Deployment
If the repository includes scripts related to the CI/CD pipeline such as scripts for TravisCI or Jenkins, refer to it for deployment. Make sure to update configurations specific to your environment accordingly. Typical scripts would include details for building the artifact and details pertaining to the deployment server.