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

    int numQubits = 33;

    Qureg QReg = createQureg(numQubits, env);
    initZeroState(QReg);

    /* start timing */
    double t0 = get_wall_time();

    // depth =   0
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
    SqX( QReg, 13 );
    SqX( QReg, 14 );
    SqX( QReg, 19 );
    SqW( QReg, 25 );
    SqY( QReg, 26 );
    fSim( QReg, 13, 19, 2.5416587438094718, -2.549249153871878 );
    SqY( QReg, 14 );
    SqY( QReg, 15 );
    SqY( QReg, 20 );
    SqX( QReg, 26 );
    SqY( QReg, 27 );
    fSim( QReg, 14, 20, -2.2920802191291694, -1.5470566283739864 );
    SqX( QReg, 15 );
    SqW( QReg, 16 );
    SqW( QReg, 21 );
    SqX( QReg, 27 );
    SqW( QReg, 28 );
    fSim( QReg, 15, 21, 0.5535988426960012, 2.9202090947995814 );
    SqW( QReg, 17 );
    SqY( QReg, 18 );
    SqX( QReg, 24 );
    SqW( QReg, 29 );
    SqX( QReg, 30 );
    fSim( QReg, 17, 24, 1.462933174370872, -2.910393432557628 );
    SqX( QReg, 18 );
    SqW( QReg, 19 );
    SqY( QReg, 25 );
    SqX( QReg, 30 );
    SqX( QReg, 31 );
    fSim( QReg, 18, 25, 0.41432117215847425, -2.7990604639705072 );
    SqX( QReg, 19 );
    SqX( QReg, 20 );
    SqW( QReg, 26 );
    SqW( QReg, 31 );
    SqX( QReg, 32 );
    fSim( QReg, 19, 26, 2.7249138788772784, -1.0869471338158265 );

    // depth =   1
    SqY( QReg, 0 );
    SqW( QReg, 1 );
    SqX( QReg, 5 );
    SqY( QReg, 11 );
    SqX( QReg, 12 );
    fSim( QReg, 5, 12, -0.9590542681439322, -0.7381949549097704 );
    SqY( QReg, 1 );
    SqX( QReg, 2 );
    SqY( QReg, 6 );
    SqW( QReg, 12 );
    SqY( QReg, 13 );
    fSim( QReg, 6, 13, 2.2065809057539156, -2.4515068114599026 );
    SqY( QReg, 2 );
    SqY( QReg, 7 );
    SqY( QReg, 13 );
    SqW( QReg, 14 );
    fSim( QReg, 7, 13, -1.4724084929209917, 1.3423639962272953 );
    SqX( QReg, 3 );
    SqW( QReg, 8 );
    SqW( QReg, 14 );
    SqY( QReg, 15 );
    fSim( QReg, 8, 14, -0.2731602178500297, 0.03269599142959836 );
    SqX( QReg, 3 );
    SqX( QReg, 4 );
    SqY( QReg, 9 );
    SqX( QReg, 15 );
    SqY( QReg, 16 );
    fSim( QReg, 9, 16, 0.5177985466551912, 1.066518776941525 );
    SqY( QReg, 5 );
    SqX( QReg, 6 );
    SqX( QReg, 12 );
    SqW( QReg, 17 );
    SqW( QReg, 18 );
    fSim( QReg, 12, 18, -1.5125796071137132, 2.8989802660588615 );
    SqW( QReg, 6 );
    SqY( QReg, 7 );
    SqW( QReg, 13 );
    SqX( QReg, 18 );
    SqY( QReg, 19 );
    fSim( QReg, 13, 19, 2.8901414941042796, -1.7566877710593278 );
    SqX( QReg, 7 );
    SqY( QReg, 8 );
    SqW( QReg, 14 );
    SqW( QReg, 19 );
    SqX( QReg, 20 );
    fSim( QReg, 14, 20, -0.5249578511085405, -1.1765233944394775 );
    SqY( QReg, 8 );
    SqW( QReg, 9 );
    SqY( QReg, 15 );
    SqW( QReg, 20 );
    SqX( QReg, 21 );
    fSim( QReg, 15, 21, -2.7889472348382998, -2.5446207076223084 );
    SqW( QReg, 9 );
    SqY( QReg, 10 );
    SqY( QReg, 16 );
    SqW( QReg, 21 );
    SqW( QReg, 22 );
    fSim( QReg, 16, 22, 2.5772010294238887, 2.081008173501727 );
    SqY( QReg, 11 );
    SqY( QReg, 12 );
    SqW( QReg, 17 );
    SqX( QReg, 23 );
    SqY( QReg, 24 );
    fSim( QReg, 17, 24, 1.1993488898704145, -0.30735115036656274 );
    SqW( QReg, 12 );
    SqY( QReg, 13 );
    SqX( QReg, 18 );
    SqW( QReg, 24 );
    SqY( QReg, 25 );
    fSim( QReg, 18, 25, -1.7588669337384222, -1.602845411062493 );
    SqW( QReg, 13 );
    SqX( QReg, 14 );
    SqW( QReg, 19 );
    SqW( QReg, 25 );
    SqW( QReg, 26 );
    fSim( QReg, 19, 26, -2.524344425683067, -2.2965454622644788 );
    SqX( QReg, 14 );
    SqY( QReg, 15 );
    SqY( QReg, 20 );
    SqX( QReg, 26 );
    SqW( QReg, 27 );
    fSim( QReg, 20, 27, -2.349043894039886, 0.17388542525734257 );
    SqW( QReg, 15 );
    SqX( QReg, 16 );
    SqW( QReg, 21 );
    SqX( QReg, 27 );
    SqX( QReg, 28 );
    fSim( QReg, 21, 28, -2.761032959053635, -1.3164896523903822 );
    SqW( QReg, 17 );
    SqY( QReg, 18 );
    SqW( QReg, 24 );
    SqW( QReg, 29 );
    SqY( QReg, 30 );
    fSim( QReg, 24, 30, 0.20254439831862384, 0.3398070122767073 );
    SqX( QReg, 18 );
    SqW( QReg, 19 );
    SqX( QReg, 25 );
    SqX( QReg, 30 );
    SqX( QReg, 31 );
    fSim( QReg, 25, 31, -2.7398516232806123, 2.512607647264222 );
    SqX( QReg, 19 );
    SqX( QReg, 20 );
    SqX( QReg, 26 );
    SqY( QReg, 31 );
    SqY( QReg, 32 );
    fSim( QReg, 26, 32, -1.2714102359512351, 2.7069603439357617 );

    // depth =   2
    SqX( QReg, 0 );
    SqY( QReg, 1 );
    SqW( QReg, 5 );
    SqX( QReg, 11 );
    SqW( QReg, 12 );
    fSim( QReg, 1, 5, 3.1345218229639253, -2.1419657162717187 );
    SqY( QReg, 1 );
    SqW( QReg, 2 );
    SqX( QReg, 6 );
    SqX( QReg, 12 );
    SqW( QReg, 13 );
    fSim( QReg, 2, 6, 2.333266135039122, -0.4056239903983968 );
    SqY( QReg, 2 );
    SqY( QReg, 7 );
    SqW( QReg, 13 );
    SqY( QReg, 14 );
    fSim( QReg, 14, 7, -2.936517098694781, -0.7371785228089204 );
    SqX( QReg, 3 );
    SqX( QReg, 8 );
    SqX( QReg, 14 );
    SqW( QReg, 15 );
    fSim( QReg, 15, 8, -2.356579381381485, 0.6455061004160539 );
    SqW( QReg, 3 );
    SqX( QReg, 4 );
    SqX( QReg, 9 );
    SqW( QReg, 15 );
    SqX( QReg, 16 );
    fSim( QReg, 4, 9, 1.5847679110405246, 2.8906853814855515 );
    SqX( QReg, 5 );
    SqY( QReg, 6 );
    SqX( QReg, 12 );
    SqY( QReg, 17 );
    SqW( QReg, 18 );
    fSim( QReg, 6, 12, -2.533661397320378, 1.2337077464179314 );
    SqY( QReg, 6 );
    SqW( QReg, 7 );
    SqY( QReg, 13 );
    SqY( QReg, 18 );
    SqX( QReg, 19 );
    fSim( QReg, 7, 13, 2.637168147483177, -2.11138682708904 );
    SqX( QReg, 7 );
    SqX( QReg, 8 );
    SqY( QReg, 14 );
    SqX( QReg, 19 );
    SqW( QReg, 20 );
    fSim( QReg, 8, 14, 1.8313940537017288, 2.9886859050177876 );
    SqY( QReg, 8 );
    SqX( QReg, 9 );
    SqW( QReg, 15 );
    SqW( QReg, 20 );
    SqY( QReg, 21 );
    fSim( QReg, 9, 15, -0.8294109227418397, 0.3465092230889221 );
    SqW( QReg, 9 );
    SqY( QReg, 10 );
    SqY( QReg, 16 );
    SqY( QReg, 21 );
    SqY( QReg, 22 );
    fSim( QReg, 10, 16, 2.44264318216502, -0.6842739267227363 );
    SqX( QReg, 11 );
    SqW( QReg, 12 );
    SqX( QReg, 17 );
    SqW( QReg, 23 );
    SqW( QReg, 24 );
    fSim( QReg, 12, 17, 2.942660809852147, 0.05436228134295264 );
    SqX( QReg, 12 );
    SqY( QReg, 13 );
    SqY( QReg, 18 );
    SqW( QReg, 24 );
    SqY( QReg, 25 );
    fSim( QReg, 13, 18, -2.1734451388716476, 2.091824252183545 );
    SqY( QReg, 13 );
    SqX( QReg, 14 );
    SqW( QReg, 19 );
    SqY( QReg, 25 );
    SqY( QReg, 26 );
    fSim( QReg, 14, 19, 1.112205321566719, 0.9999605977204754 );
    SqX( QReg, 14 );
    SqW( QReg, 15 );
    SqW( QReg, 20 );
    SqX( QReg, 26 );
    SqW( QReg, 27 );
    fSim( QReg, 15, 20, 1.8367861085237533, -1.2302584243508599 );
    SqY( QReg, 15 );
    SqX( QReg, 16 );
    SqY( QReg, 21 );
    SqW( QReg, 27 );
    SqW( QReg, 28 );
    fSim( QReg, 16, 21, 0.6497759929138813, -0.7018565911030121 );
    SqW( QReg, 17 );
    SqW( QReg, 18 );
    SqW( QReg, 24 );
    SqY( QReg, 29 );
    SqW( QReg, 30 );
    fSim( QReg, 18, 24, -0.8230788196715534, -2.8378412443270884 );
    SqW( QReg, 18 );
    SqY( QReg, 19 );
    SqX( QReg, 25 );
    SqY( QReg, 30 );
    SqX( QReg, 31 );
    fSim( QReg, 19, 25, 0.06601625444961617, 1.0955432939643415 );
    SqY( QReg, 19 );
    SqY( QReg, 20 );
    SqW( QReg, 26 );
    SqW( QReg, 31 );
    SqY( QReg, 32 );
    fSim( QReg, 20, 26, -0.21413436425696253, -2.8217556447834338 );

    for (int ind=0; ind<numQubits; ++ind){
        mysteryGate(QReg, ind, (ind+1)%numQubits);
        mysteryGate(QReg, ind, (ind+2)%numQubits);
        mysteryGate(QReg, ind, (ind+3)%numQubits);
        mysteryGate(QReg, ind, (ind+4)%numQubits);
        mysteryGate(QReg, ind, (ind+5)%numQubits);
        mysteryGate(QReg, ind, (ind+6)%numQubits);
        mysteryGate(QReg, ind, (ind+7)%numQubits);
        mysteryGate(QReg, ind, (ind+8)%numQubits);
        mysteryGate(QReg, ind, (ind+9)%numQubits);
        mysteryGate(QReg, ind, (ind+10)%numQubits);
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
