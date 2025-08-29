class Network {
public:
    //...
    enum class ErrorCode { Timeout, ConnectionRefused };
};

class Database {
public:
    enum class ErrorCode { ConstraintViolation, NotFound };
};


Network::ErrorCode neterr = Network::ErrorCode::Timeout;
Database::ErrorCode dberr = Database::ErrorCode::NotFound;
