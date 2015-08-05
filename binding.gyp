{
  "targets": [
    {
      "target_name": "init",
      "sources": [
        "src/init.cc",
        "src/color.cc",
        "src/qr_image.cc",
        "src/qr_cairo.cc"
      ], 
      "libraries": [
        "<!@(pkg-config cairo --libs)",
        "<!@(pkg-config libqrencode --libs)"
      ],
      "include_dirs": [
        "<!@(pkg-config cairo --cflags-only-I | sed s/-I//g)",
        "<!@(pkg-config libqrencode --cflags-only-I | sed s/-I//g)"
      ]
    }
  ]
}
