# Exercise 01 : Don't you wish your framework was Qt like you?

Qt is a cross-platform framework for creating applications. It allows to create C++ applications for every operating system without much hassle.
Qt Creator is a cross platform IDE with tools for designing and developing applications with the Qt application framework. It allows developers to create applications once and run them on desktop, mobile, and embedded platforms.

**Key Concepts:**

* **Qt Widgets:** An application created with Qt Widgets looks like a native desktop application. However, on other platforms such as mobile or embedded, there is no native style available for widgets. As such, these are only suitable when you only need to target desktop platforms. Qt recommends using Qt Quick.

* **Qt Quick:** It's a more modern way of creating applications with Qt. Typically used for writing QML (based on JavaScript - see Introduction to QML). Looks native and is available on all platforms. We can visually create Qt Quick UIs using Qt Design Studio and import the designs to Qt Creator. This supports the workflow between designers, technical artists and software developers.

Qt Creator groups settings used for building and running projects as kits to make cross-platform and cross-configuration development easier. Each kit consists of a set of values that define one environment, such as a device, compiler, Qt version, and debugger command to use, and some metadata, such as an icon and a name for the kit.

We can learn more about QT @ [academy.qt.io](academy.qt.io)