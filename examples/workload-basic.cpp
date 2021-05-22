#include <stdio.h>
#include "QuEST.h"
#include <assert.h>
#include "mytimer.hpp"

int main () {

    QuESTEnv env = createQuESTEnv();
    
    FILE *fp, *fvec;
    if(env.rank==0){

        fp=fopen("probs.dat", "w");
        if(fp==NULL){
            printf("    open probs.dat failed, Bye!");
            return 0;
        }

        fvec=fopen("stateVectors.dat", "w");
        if(fvec==NULL){
            printf("    open stateVector.dat failed, Bye!");
            return 0;
        }
    }

    int numQubits = 26;

    Qureg QReg = createQureg(numQubits, env);
    initZeroState(QReg);

    /* start timing */
    double t0 = get_wall_time();

    SqW( QReg, 0 );
    SqW( QReg, 1 );
    SqW( QReg, 5 );
    SqY( QReg, 11 );
    SqW( QReg, 12 );
    fSim( QReg, 0, 5, -0.9274470782389919, 1.1916705004129888 );

    SqY( QReg, 1 );
    SqW( QReg, 2 );
    SqX( QReg, 6 );
    SqY( QReg, 12 );
    SqW( QReg, 13 );
    fSim( QReg, 1, 6, -0.4555642653771102, -2.641565048571904 );

    SqX( QReg, 2 );
    SqY( QReg, 7 );
    SqW( QReg, 13 );
    SqY( QReg, 14 );
    fSim( QReg, 2, 7, 2.090215340683649, -0.3276386992393226 );

    SqW( QReg, 3 );
    SqW( QReg, 8 );
    SqY( QReg, 14 );
    SqW( QReg, 15 );
    fSim( QReg, 3, 8, -0.4846558586160135, -1.2515117331944738 );

    SqX( QReg, 3 );
    SqW( QReg, 4 );
    SqX( QReg, 9 );
    SqW( QReg, 15 );
    SqW( QReg, 16 );
    fSim( QReg, 3, 9, -2.0497279689270793, 0.6675858108948606 );

    SqW( QReg, 5 );
    SqX( QReg, 6 );
    SqY( QReg, 12 );
    SqW( QReg, 17 );
    SqW( QReg, 18 );
    fSim( QReg, 5, 12, 1.2500019157553346, 1.2216952937234355 );

    SqY( QReg, 6 );
    SqX( QReg, 7 );
    SqY( QReg, 13 );
    SqY( QReg, 18 );
    SqX( QReg, 19 );
    fSim( QReg, 6, 13, 0.004872390010860335, -3.0524118982794803 );

    SqY( QReg, 7 );
    SqW( QReg, 8 );
    SqY( QReg, 14 );
    SqW( QReg, 19 );
    SqY( QReg, 20 );
    fSim( QReg, 7, 14, -1.2418731774081297, -0.5699964885220595 );

    SqY( QReg, 8 );
    SqY( QReg, 9 );
    SqY( QReg, 15 );
    SqY( QReg, 20 );
    SqY( QReg, 21 );
    fSim( QReg, 8, 15, 2.7078867217146634, 2.1885645327257053 );

    SqW( QReg, 9 );
    SqY( QReg, 10 );
    SqX( QReg, 16 );
    SqY( QReg, 21 );
    SqX( QReg, 22 );
    fSim( QReg, 9, 16, -0.7051711648582605, 2.22914396662269 );

    SqX( QReg, 11 );
    SqX( QReg, 12 );
    SqX( QReg, 17 );
    SqY( QReg, 23 );
    SqY( QReg, 24 );
    fSim( QReg, 11, 17, -1.840978993767009, -0.002313558501654947 );

    SqX( QReg, 12 );
    SqW( QReg, 13 );
    SqY( QReg, 18 );
    SqW( QReg, 24 );
    SqX( QReg, 25 );
    fSim( QReg, 12, 18, -2.348193821651514, -2.239884609233249 );

    for (int ind=0; ind<numQubits; ++ind){
        mysteryGate(QReg, ind, (ind+1)%numQubits);
        mysteryGate(QReg, ind, (ind+2)%numQubits);
        mysteryGate(QReg, ind, (ind+3)%numQubits);
        mysteryGate(QReg, ind, (ind+4)%numQubits);
        mysteryGate(QReg, ind, (ind+5)%numQubits);
    }
    
    qreal prob;
    for(int ind=0; ind<numQubits; ++ind){
        prob = calcProbOfOutcome(QReg, ind, 1);
        if(env.rank==0){
            printf("Prob of qubit %2d (outcome=1) is: %12.6f\n", ind, prob);
            fprintf(fp, "Prob of qubit %2d (outcome=1) is: %12.6f\n", ind, prob);
        }
    }

    for(int i=0; i<10; ++i){
        Complex amp = getAmp(QReg, i);
	    if(env.rank==0) fprintf(fvec, "Amplitude of %dth state vector: %12.6f,%12.6f\n", i, amp.real, amp.imag);
    }

    /* finish timing */
    double t = get_wall_time() - t0;
    if(env.rank==0) printf("Time cost: %lf\n", t);

    destroyQureg(QReg, env);
    destroyQuESTEnv(env);

    return 0;
}
