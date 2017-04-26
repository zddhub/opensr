Open Sketch Recognize
=====================

This is another [OpenSSE demo](http://sr.opensse.com), supported by [OpenSSE](https://github.com/zddhub/opensse).

*Note:* Strictly speaking, this demo is based on **search** method, not **recognize** method now.


Demo - SketchRecognizeDemo
==========================

[Try via web](http://online.opensse.com)

See more recognize results, click [demo videos](http://sr.opensse.com).

![Sketch recognize demo](assets/opensr.gif "Sketch recognize demo")


How to install
==============

After installed [OpenSSE](https://github.com/zddhub/opensse), You can compile it like below:

```sh
cd gui/SketchRecognizeDemo
mkdir release && cd release
qmake -o Makefile ../SketchRecognizeDemo.pro
make
```


Database
========

Sketch database comes from Mathias Eitz's paper [How Do Humans Sketch Objects? ACM Transactions on Graphics (Proc. SIGGRAPH 2012)](http://cybertron.cg.tu-berlin.de/eitz/projects/classifysketch/).

If you want to use your data, please refer to [OpenSSE Wiki](https://github.com/zddhub/opensse/wiki/How-to-train-data), train and update your own `sketches_filelist`、`sketches_index_file` and `vocabulary`.


Thanks
======
- [Mathias Eitz](http://cybertron.cg.tu-berlin.de/eitz/)


License
=======

Code is under the [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0).


Donations
=========

I accept tips through [Alipay](assets/zddhub.png). Scan below qr code to donate:

[[assets/zddhub.png]]


Contact me
==========

If you have any question or idea, please [email to me](mailto:zddhub@gmail.com).
