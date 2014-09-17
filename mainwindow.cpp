#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // lol a comment

    QFileSystemModel *model = new QFileSystemModel();
    model->setRootPath(QDir::currentPath());
    ui->fileBackupTreeView->setModel(model);

    // connect buttons
    connect(ui->activePathToolButton, SIGNAL(clicked()),
            this, SLOT(displayFolderSelection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayFolderSelection() {
    QString newDir = QFileDialog::getExistingDirectory(this, tr("Find Folder"));
    ui->activePathLineEdit->setText(newDir);
}
