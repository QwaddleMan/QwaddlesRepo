
//Author: Jason Bowerman
//Description: this is the webserver
// that hosts my webpage
var express = require('express');//using express

var app = express();
var server = app.listen(29202);//listen to port

app.use(express.static('public'));

app.post('/', function(req, res){

});

console.log("Go Server! Go!");//woop woop
