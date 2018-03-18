# Ti.PinchView

This is fork of the module of Joaquín Lovera <img src="https://avatars3.githubusercontent.com/u/4253527?s=460&v=4" width=50 />

Only the iOS version of TiView has apinch event. With this event you can use it for android too. In my last project I use it in addition to Ti.CanvasView to zoom the chart.

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
win.add(Pincher);


```
