CREATE USER 'test_user'@'localhost' IDENTIFIED BY 'password';
GRANT all ON test_db.* TO 'test_user'@'localhost';
