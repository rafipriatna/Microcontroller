const express = require("express");
const bodyParser = require("body-parser");
const cors = require("cors");

const app = express();

// Models
const db = require("./app/models");

// CORS
let allowList = [
    'http://localhost:8081',
];

let corsOption = {
    origin: (origin, callback) => {
        if (allowList.indexOf(origin) !== -1 || !origin) {
            callback(null, true);
        } else {
            callback(new Error('Not allowed.'));
        }
    }
}

app.use(cors(corsOption));

// Parse Request
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

// Create DB Table from model
db.sequelize.sync();

// Routes
app.get("/", (req, res) => {
    res.json({
        message: "Halo Dunia!"
    });
});

require("./app/routes/button.route")(app);

// Server
const PORT = process.env.PORT || 8080;
app.listen(PORT, () => {
    console.log(`Server udah jalan di http://localhost:${PORT}`);
});
