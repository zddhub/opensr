Open Sketch Recognize
=====================

This is another [opensse demo](http://sr.opensse.com), supported by [opensse](https://github.com/zddhub/opensse).

Demo - SketchRecognizeDemo
==========================

See more search results, click [demo videos](http://sr.opensse.com).

![demo video](http://img.blog.csdn.net/20140520195606468)

Database
========

Sketch database comes from Mathias Eitz's paper [How Do Humans Sketch Objects? ACM Transactions on Graphics (Proc. SIGGRAPH 2012)](http://cybertron.cg.tu-berlin.de/eitz/projects/classifysketch/).

How to use
==========
First, you need config [opensse](https://github.com/zddhub/opensse), and include you opensse path to `SketchRecognizeDemo.pro` file.
```cpp
include(/Users/zdd/Projects/opensse/opensse.pri)
```

And then, You need config `params.json` file depend on you path. All data are shared on my [Dropbox](https://www.dropbox.com/sh/v2lo3qnguff1cuq/AADc1569j51vDW4ypvjFPF8ka).
```json
{
    "searcher":
    {
        "indexfile": "/Users/zdd/Projects/opensr/data/sketchs_index_file",
        "filelist": "/Users/zdd/Projects/opensr/data/sketchs_filelist",
        "vocabulary": "/Users/zdd/Projects/opensr/data/vocabulary",
        "rootdir": "",
        "results_num": "1",
        "views_num": "1"
    }
}
```

Last, read your json file:
```cpp
boost::property_tree::read_json("/Users/zdd/Projects/opensr/data/params.json", params); 
```

Thanks
======
- [Mathias Eitz](http://cybertron.cg.tu-berlin.de/eitz/)

License
=======

Code is under the [Apache License, Version 2.0](http://www.apache.org/licenses/LICENSE-2.0).

Donations
=========

I accept tips through [Alipay](http://img.blog.csdn.net/20140506233949640). Scan below qr code to donate:

![Alipay](http://img.blog.csdn.net/20140506233949640 "Donation").

Contact me
==========

If you have any question or idea, please [email to me](mailto:zddhub@gmail.com).
