# Ti.PinchView

This is fork of the module of Joaquín Lovera <img src="https://avatars3.githubusercontent.com/u/4253527?s=460&v=4" width=50 />

Only the iOS version of TiView has a pinch event. With this event you can use it for android too. In my last project I use it in addition to Ti.CanvasView to zoom a solr facet driven chart.

<img src="https://raw.githubusercontent.com/AppWerft/Ti.PinchView/master/screen.png" width=200 />

(For zooming the graphic in the top right corner)

## Usage

```javascript

var win = Ti.UI.createWindow();
var Pincher = require("ti.pinchview").createPinchView({
	backgroundColor:'transparent',
	minZoomValue:0.5,
	maxZoomValue:2
});
Pincher.addEventListener("multiStart",function(e){
});
Pincher.addEventListener("multiMove",function(e){
});
Pincher.addEventListener("pinch",function(e){
});
Pincher.addEventListener("pinchEnd",function(e){
});
Pincher.addEventListener("click",function(e){
});
win.add(Pincher);


```
