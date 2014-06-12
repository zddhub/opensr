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

#include <iostream>

using namespace std;

#include "recognize/sketchrecognizer.h"
using namespace sse;


void usage() {
    cout << "Usage: "<<endl;
    cout << "\t" << "sr -t sketchs labels svmfile" <<endl;
    cout << "\t" << "sr -p svmfile labels vocabulary sketch" <<endl;
}

int main(int argc, char **argv)
{
    if(argc != 5 && argc != 6) {
        usage();
        exit(1);
    }

    SketchRecognizer sr;
    //
    if(argv[1][1] == 't') {
        sr.train(argv[2], argv[3],argv[4]);
    } else {
        cout << "load svm ... "<<flush;
        sr.load(argv[2], argv[3],argv[4]); //Just need run once
        cout << "done." <<endl;
        string label;
        sr.predict(argv[5], label); //so far, for training data, it's good.
        cout <<label << endl;
    }

    return 0;
}

