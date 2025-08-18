pipeline {
    agent any

    environment {
        DEPLOY_DIR = '/var/www/myapp'
        APP_ENTRY = 'myapp.py'
    }

    stages {
        stage('Clone Repository') {
            steps {
                git url: 'https://github.com/your-username/your-repo.git'
            }
        }

        stage('Build') {
            steps {
                echo 'Building the application...'
                // Example: Compile Java, install Python deps, etc.
                // sh 'javac MyApp.java' or 'pip install -r requirements.txt'
            }
        }

        stage('Test') {
            steps {
                echo 'Running tests...'
                // Optional: run test scripts or unit tests
                // sh 'python -m unittest tests/test_app.py'
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploying application...'
                sh """
                    mkdir -p $DEPLOY_DIR
                    cp -r * $DEPLOY_DIR/
                    pkill -f $APP_ENTRY || true
                    nohup python3 $DEPLOY_DIR/$APP_ENTRY > $DEPLOY_DIR/output.log 2>&1 &
                """
            }
        }
    }

    post {
        success {
            echo '✅ Deployment successful!'
        }
        failure {
            echo '❌ Deployment failed.'
        }
    }
}

