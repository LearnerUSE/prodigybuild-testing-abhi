```markdown
# prodigybuild-testing

This repository contains a web application that is to be improved along the way. The application is developed using Node.js and Express for the backend, with React.js for the frontend. For storage, we are using MongoDB.

## Prerequisites

- Node.js (v14.16.0 or later)
- MongoDB (v4.2 or later)
- Yarn package manager (v1.22 or later)

## Installation and Setup

### For MacOS

1. Install Node.js & Yarn
    ```bash
    brew install node@14
    brew install yarn
    ```
2. Install MongoDB
    ```bash
    brew tap mongodb/brew
    brew install mongodb-community@4.2
    ```

### For Windows

1. Download and Install Node.js via [official website](https://nodejs.org/en/download/)
2. Install Yarn
    ```bash
    npm install -g yarn
    ```
3. Download and Install MongoDB via [official website](https://www.mongodb.com/try/download/community)

## Install Project Dependencies

1. Clone the repository
    ```bash
    git clone https://github.com/[username]/prodigybuild-testing.git
    ```
2. Navigate into the folder
    ```bash
    cd prodigybuild-testing/
    ```
3. Install the dependencies
    ```bash
    yarn install
    ```

## Running The Project Locally

1. Start MongoDB
    ```bash
    brew services start mongodb-community@4.2    # MacOS
    "C:\Program Files\MongoDB\Server\4.2\bin\mongod.exe" --dbpath="c:\data\db"    # Windows
    ```
2. Run the server
    ```bash
    yarn start
    ```

The application can now be accessed on `http://localhost:3000`

## Deployment process

For CI/CD, we are using GitHub Actions. When a commit is pushed or a pull request is made on the `master` branch, the pipeline is automatically triggered. The pipeline does the following:

1. Perform a build.
2. Runs tests to make sure everything is working fine.
3. If the tests are successful, the build is deployed to the server.

The application is running live on `https://www.prodigybuild-testing.com`

## Environments

- **Development**: This is your local setup on your system. When you run the app on your local machine, you are running it in the development environment.
  
- **Production**: This is where the app lives for the users to use it. The code here should be stable and tested through staging environment.
  
- **Staging**: Code in this environment is as close to a simulation of the production environment as possible. This helps in catching any last minute bugs before the code is deployed to production.

Make sure to run `yarn install` whenever you switch the environment.
```
