const db = require("../models");
const op = db.Sequelize.Op;
const Button = db.buttons;

// Create
exports.create = (req, res) => {
    // Validate
    if (!req.body) {
        res.status(400).send({
            message: "Data tidak boleh kosong!"
        });
        return
    }

    const button = {
        name: req.body.name,
        pin: req.body.pin,
        status: req.body.status ? req.body.status : false,
    };

    Button.create(button).then(result => {
        res.send(result);
    }).catch(err => {
        res.status(500).send({
            message: err.message || "Error!"
        });
    });
};

// Get All
exports.findAll = (req, res) => {
    Button.findAll().then(result => {
        res.send(result);
    }).catch(err => {
        res.status(500).send({
            message: err.message || "Error!"
        });
    });
};

// Get Single
exports.findOne = (req, res) => {
    Button.findOne({
        where: {
            id: req.params.id
        }
    }).then(result => {
        res.send(result);
    }).catch(err => {
        res.status(500).send({
            message: err.message || "Error!"
        });
    });
};

// Update
exports.update = (req, res) => {
    Button.update(req.body, {
        where: {
            id: req.params.id
        }
    }).then(result => {
        res.send(result);
    }).catch(err => {
        res.status(500).send({
            message: err.message || "Error!"
        });
    });
}

// Delete
exports.delete = (req, res) => {
    Button.destroy({
        where: {
            id: req.params.id
        }
    }).then(result => {
        res.status(200).send({
            message: "Berhasil menghapus data!"
        });
    }).catch(err => {
        res.status(500).send({
            message: err.message || "Error!"
        });
    });
};
