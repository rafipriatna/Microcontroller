const five = require('johnny-five');
const express = require('express');

const board = new five.Board({
    rep1: false
});
const app = express();
const http = require('http').createServer(app);
const io = require('socket.io')(http);

board.on('ready', () => {
    io.on('connection', socket => {
        console.log('a user connected');
        socket.on('disconnect', () => {
            console.log('user disconnected');
        });

        const ledRed = new five.Led(2); // Led Red pin 2
        const ledYellow = new five.Led(3);
        const ledGreen = new five.Led(4);

        socket.on('switchRed', data => {
            data? ledRed.on(): ledRed.off()
        });
        socket.on('switchYellow', data => {
            data? ledYellow.on(): ledYellow.off()
        });
        socket.on('switchGreen', data => {
            data? ledGreen.on(): ledGreen.off()
        });

    });
});

// Server
const PORT = process.env.PORT || 8080;
http.listen(PORT, () => {
    console.log(`Server udah jalan di http://localhost:${PORT}`);
});
