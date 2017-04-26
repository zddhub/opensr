Open Sketch Recognize
=====================

[Try via web](http://online.opensse.com).

This is another [OpenSSE demo](http://sr.opensse.com), supported by [OpenSSE](https://github.com/zddhub/opensse).

*Note:* Strictly speaking, this demo is based on **search** method, not **recognize** method now.


How to compile
==============

After installed [OpenSSE](https://github.com/zddhub/opensse) and [Qt 5.1+](https://www.qt.io), You can compile this like below:

```sh
cd gui/SketchRecognizeDemo
mkdir release && cd release
qmake -o Makefile ../SketchRecognizeDemo.pro
make
```


Demo - SketchRecognizeDemo
==========================

After compiled, you will have our SketchSearchDemo app under `bin` folder, open it like blow:

![Sketch recognize demo](assets/opensr.gif "Sketch recognize demo")

By the way, press 'C' in sketch pad, You will clear the sketch and draw next one.


See more recognize results, click [demo videos](http://sr.opensse.com).


Database
========

Sketch database comes from Mathias Eitz's paper [How Do Humans Sketch Objects? ACM Transactions on Graphics (Proc. SIGGRAPH 2012)](http://cybertron.cg.tu-berlin.de/eitz/projects/classifysketch/).

If you want to train your database, please refer to [OpenSSE Wiki](https://github.com/zddhub/opensse/wiki/How-to-train-data), you will get your own `sketches_filelist`、`sketches_index_file` and `vocabulary` file, and then update `config.json`.


Thanks
======
- [Mathias Eitz](http://cybertron.cg.tu-berlin.de/eitz/)


License
=======

Code is under the [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0).


Donations
=========

I accept tips through [Alipay](assets/zddhub.png). Scan below qr code to donate:

![Alipay](assets/zddhub.png "Donation")


Contact me
==========

If you have any question or idea, please [email to me](mailto:zddhub@gmail.com).
