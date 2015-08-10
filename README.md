QR Code generator for node
=========================

Another [QR code](https://en.wikipedia.org/wiki/QR_code) library for nodejs, aiming at allowing more customization on your QR code result :
- changing background
- changing code color
(still needs some work)

This library is based on the native Cairo and libqrencode library, so as requirements
you should have this two libraries installed on your OS :
* Cairo library http://www.cairographics.org/download/ 
* libqrencode https://fukuchi.org/works/qrencode/

Installation
------------
Use npm.
```shell
npm install qr-cairo
```

Usage
-----
The code below shows a basic example of generating an image with gr-cairo with default settings : transparent background, black foreground and correction level to "low".

```javascript
var qr_cairo = require('qr-cairo');

// Qr without options
qr_cairo.save('http://aminekabab.me/blog', 'test1.png');
```

Advanced Usage
--------------

Currently qr-cairo has one method that generates the qr image 
```javascript
qr_cairo.save(value, path [, options])
```

``value`` is the message that you want to encode as Qr code

``path`` the path where you want to save the generated image

``option`` JSON object that can contain the following parameters

``option.back_color`` the background color in hexadecimal format (default color is transparent)

``option.fill_color`` foreground color (default : #000000)

``option.ec_level`` error correction level ('L' : LOW, 'M' : MEDIUM, 'Q' : QUALITY, 'H', HIGH)

``option.box_size`` the box size in pixel of the qrcode

```javascript
var qr_cairo = require('qr-cairo');

// Qr with options 
var options = {'ec_level': 'l', 'box_size': '20', 'back_color': '#ee4444', 'fill_color': '#222200'};
qr_cairo.save("Amine", "test2.png", options);
```

