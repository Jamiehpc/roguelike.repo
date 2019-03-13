#ifndef DUNGEON_H
#define DUNGEON_H


class Dungeon
{
    public:
        Dungeon();
        virtual ~Dungeon();
        void Randomise();

    protected:

    private:

    int m_dungeonSize{0}; //number of rooms

};

#endif // DUNGEON_H
