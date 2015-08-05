=========================
Qr Code genartor for node
=========================

Another Qr library for nodejs, but this one you could customize more things on you Qr code result,
 (still needs some work), the current version support a lot of stuff like changing background and code color.

This library is based on the native Cairo library and libqrencode library, so as requirements
you should had this two libraries on your OS.

You can get Cairo library from here http://www.cairographics.org/download/ 

And libqrencode from here https://fukuchi.org/works/qrencode/

Installation
------------
To install qr-cairo you can download the library and install easily with npm command

```shell
npm install qr-cairo
```

Usage
-----
The code below show a basic example of generating an image with Qr code, the genereted code will had
as default, transparent background color, black filling color and the correction level by default is low.

```javascript
var qr_cairo = require('qr-cairo');

// Qr without options
qr_cairo.save('http://aminekabab.me/blog', 'test1.png');
```

Advanced Usage
--------------

Currently qr-cairo has one method that generate the qr image 
```javascript
qr_cairo.save(value, path [, options])
```

``value`` is the message that you want to encode as Qr code

``path`` the path where you want to save the generated image

``option`` JSON object that can contain the following parameters

``option.back_color`` the background color in hexadecimal format (default color is transparent)

``option.fill_color`` code drawing color (default : #000000)

``option.ec_level`` error correction level ('L' : LOW, 'M' : MEDIUM, 'Q' : QUALITY, 'H', HIGH)

``option.box_size`` the box size in pixel in the qrcode

```javascript
var qr_cairo = require('qr-cairo');

// Qr with options 
var options = {'ec_level': 'l', 'box_size': '20', 'back_color': '#ee4444', 'fill_color': '#222200'};
qr_cairo.save("Amine", "test2.png", options);
```

