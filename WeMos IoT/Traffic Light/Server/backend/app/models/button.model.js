module.exports = (sequelize, Sequelize) => {
    const Button = sequelize.define("button", {
        name: {
            type: Sequelize.STRING,
        },
        pin: {
            type: Sequelize.STRING
        },
        status: {
            type: Sequelize.BOOLEAN
        }
    });

    return Button;
}