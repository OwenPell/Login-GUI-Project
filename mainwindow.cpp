#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>
#include<QVector>

QVector<QString> usernames;
QVector<QString> passwords;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginManager)
{
    ui->setupUi(this);

    connect(ui->login, SIGNAL(clicked()), this, SLOT(loginButton())); //Pointer to login button

    connect(ui->signUp, SIGNAL(clicked()), this, SLOT(signUpButton())); //Pointer to sign up button
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::signUpButton() //Sign up button on-click function
{
    QString userName = ui->userEnter->text(); //Creates a string variable that stores user input from the 'userEnter' text box
    QString userPass = ui->passEnter->text(); //Creates string variable that stores user input from the 'passEnter' text box

    if(userName == ""){ //Ensures that the user cannot leave userName or userPass blank
        QMessageBox::information(this, "ERROR", "Username field cannot be NULL");
    } else if(userPass == ""){
        QMessageBox::information(this, "ERROR", "Password field cannot be NULL");
    } else {
        usernames.push_back(userName); //Appends the value of variable userName to 'usernames' vector
        passwords.push_back(userPass); //Appends the value of variable passEnter to 'passwords' vector

        QMessageBox::information(this, "Welcome Message", "New User: "+userName+"\n" "Welcome To Login Manager"); //Displays popup message displaying the newly added username
    }

}

void MainWindow::loginButton() //Log in button on-click function
{
    QString userName = ui->userEnter->text(); //Creates a string variable that stores user input from the 'userEnter' text box
    QString userPass = ui->passEnter->text(); //Creates string variable that stores user input from the 'passEnter' text box
    bool userMatch = false; //Assumes user input does not match anything in vector

    for(int i = 0; i < usernames.size(); i++){ //Iterates through usernames vector to check user input against any values in usernames and passwords
        if(userName == usernames[i] && userPass == passwords[i]){ //If userName AND userPass match the vectors usernames and passwords, a welcome back popup is displayed
            QMessageBox::information(this, "Welcome Message", "User: "+usernames[i]+"\n" "Welcome Back to Login Manager");
            userMatch = true;
            break;
        }
    }

    if(!userMatch){ //If userMatch remains false, the nested if statement checks for any null fields or non-matching username/password
        if(userName == ""){
            QMessageBox::information(this, "ERROR", "Username field cannot be NULL");
        } else if(userPass == ""){
            QMessageBox::information(this, "ERROR", "Password field cannot be NULL");
        } else{
            QMessageBox::information(this, "ERROR", "Invalid username or password ");
        }
    }
}

