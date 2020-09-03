module.exports = {
    HOST: "localhost",
    USER: "root",
    PASS: "",
    DB: "node_arduino",
    dialect: "mysql",
    pool: {
        max: 5,
        min: 0,
        acquire: 30000,
        idle: 10000,
    },
};