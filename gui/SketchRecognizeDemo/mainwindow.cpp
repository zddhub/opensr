/*************************************************************************
 * Copyright (c) 2014 Zhang Dongdong
 * All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
**************************************************************************/
#include "mainwindow.h"
#include <QVBoxLayout>

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QDir>
#include <QFont>

#include "sketchsearcher.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resultLabel = new QLabel;
    QFont font = resultLabel->font();
    font.setPointSize(30);
    resultLabel->setFont(font);
    resultLabel->setAlignment(Qt::AlignCenter);

    sketchArea = new SketchArea;
    sketchArea->setAutoSaveSketch(true);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(resultLabel);
    layout->addWidget(sketchArea);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    this->setCentralWidget(widget);

    sketchRecognizer = new sse::SketchRecognizer;
//    sketchRecognizer->load("/Users/zdd/Database/recognize/svmfile", "/Users/zdd/Database/recognize/sketchs_labels",
//                           "/Users/zdd/Database/recognize/vocabulary");

    sse::PropertyTree_t params;
    boost::property_tree::read_json("/Users/zdd/Database/recognize/params.json", params); //
    searchEngine = new SketchSearcher(params);

    connect(sketchArea, SIGNAL(newSketchDone(QString)), this, SLOT(predict(QString)));
    connect(sketchArea, SIGNAL(clearSketchDone()), this, SLOT(clearResults()));

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QAction *openAction = fileMenu->addAction(tr("&Open"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(),
                                                    tr("Images (*.png *.bmp *.jpg)"));

    if(!fileName.isEmpty())
    {
        sketchArea->openImage(fileName);
    }
}

void MainWindow::predict(const QString &fileName)
{
    std::string label;
    //sketchRecognizer->predict(fileName.toStdString(), label);
    QueryResults results;
    searchEngine->query(fileName.toStdString(), results);
    resultLabel->setText(results[0].imageName.c_str());
}

void MainWindow::clearResults()
{
    resultLabel->setText("");
}

MainWindow::~MainWindow()
{

}
