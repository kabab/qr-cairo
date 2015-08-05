================================================================
Qr Code genartor for node based on cairo library and libqrencode
================================================================

Installation
------------
```shell
npm install qr-cairo
```

Usage
-----

```javascript
var qr_cairo = require('qr-cairo');

// Qr without options
qr_cairo.save('http://aminekabab.me/blog', 'test1.png');
```

Advanced Usage
--------------

```javascript
var qr_cairo = require('qr-cairo');

// Qr with options 
var options = {'ec_level': 'l', 'box_size': '20', 'back_color': '#ee4444', 'fill_color': '#222200'};
qr_cairo.save("Amine", "test2.png", options);
```

