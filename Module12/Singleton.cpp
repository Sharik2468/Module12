class GameInstance
{
private: //unaviable for client
    GameInstance() {}
    GameInstance(const GameInstance&);
    GameInstance& operator=(GameInstance&);
public:
    static GameInstance& getInstance() { //full access
        static GameInstance instance;
        return instance;
    }
};