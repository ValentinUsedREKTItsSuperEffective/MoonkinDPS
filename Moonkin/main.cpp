#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct FeuStellaire {

    short damageMin = 540;
    short damageMax = 636;
    short damageDiff;
    float castingDuration = 3.5f;
    float castingTime = 0.f;

    FeuStellaire(){
        damageDiff = damageMax - damageMin;
    }

    short Cast(float step){
        castingTime += step;

        if(castingTime < castingDuration){
            return 0.f;
        }

        castingTime = fmod(castingTime, castingDuration);
        return rand() % damageMin + damageDiff;
    }

};

int main(){
    srand (time(NULL));

    FeuStellaire fs;

    short sec = 0;
    short fightTotalDuration = 360;
    float fightCurrentDuration = 0.00001f;
    float step = .5f;

    int totalDamage = 0.f;
    float dps = 0.f;

    for(float i = 0; i <= fightTotalDuration; i += step, fightCurrentDuration += step){
        totalDamage += fs.Cast(step);
        dps = totalDamage / fightCurrentDuration;
    }

    cout << "DPS : " << dps << " over " << sec << " seconds." << endl;
    return 0;
}
