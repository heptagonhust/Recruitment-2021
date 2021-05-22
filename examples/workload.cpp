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

    int numQubits = 34;
    int halfnum = numQubits/2;

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
