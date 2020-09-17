module.exports = app => {
    const buttons = require("../controllers/button.controller");
    
    let router = require("express").Router();

    router.post("/", buttons.create);
    router.get("/", buttons.findAll);
    router.get("/:id", buttons.findOne);
    router.patch("/:id", buttons.update);
    router.delete("/:id", buttons.delete);

    app.use("/api/buttons", router);
}
