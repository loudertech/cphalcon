Phalcon PHP Framework
=====================

Phalcon PHP is a web framework delivered as a C extension providing high performance and lower resource consumption

Get Started
-----------

Phalcon PHP is written in C with platform independence in mind. As a result, Phalcon PHP is available on Microsoft Windows, GNU/Linux, Mac OS X, You can either download a binary package for the system of your choice or build it from sources.
### Windows

For use phalcon on windows you only should to download a DLL library. Edit your php.ini file and then add:

     extension=php_phalcon.dll

Finally restart your webserver. You can download DLL for Windows from http://phalconphp.com/downloads

### GNU/Linux

On GNU/Linux platform you can easily compile and install the extension from source code.

#### Requirements
We need some packages previously installed.

* PHP 5.x development resources
* GCC compiler

Ubuntu:

    sudo apt-get install php5-dev php5-mysql gcc make

Suse:

    yast2 -i php5-pear php5-dev libmysqlclient gcc make autoconf2.13

Compilation
-----------

We need to compile a shared library from C source to generate phalcon.so extension:

     # git clone git://github.com/phalcon/cphalcon.git
     # cd cphalcon/target/release
     # export CFLAGS="-O2 -fno-delete-null-pointer-checks"
     # phpize
     # ./configure --enable-phalcon
     # make
     # sudo make install
 
Add extension to your php.ini

     extension=phalcon.so

Finally restart the webserver

Current Build Status
--------------------

Phalcon PHP Framework is built under Travis CI service. Every commit pushed up to this repository
will queue a build into the continuos integration service and will run all phpunit tests to ensure that 
everything is going well and the project is stable. The current build status is:

[![Build Status](https://secure.travis-ci.org/phalcon/cphalcon.png?branch=master)](http://travis-ci.org/phalcon/cphalcon)


License
--------------

See the docs/LICENSE.txt file.
