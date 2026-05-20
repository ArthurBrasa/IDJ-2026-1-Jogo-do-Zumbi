#ifndef TIMER_H
#define TIMER_H

class Timer {
    public:
        Timer();
        void  update(float dt);
        void  restart();
        float get();
    private:
        float time;
};

#endif
