#include <stdio.h>

int main() {
    long long amendoim, branco, leite;
    long long E, P, S;
    
    scanf("%lld %lld %lld", &amendoim, &branco, &leite);

    for (E = 0; E <= amendoim / 150 && E <= branco / 750 && E <= leite / 600; E++) {
        
        long long maxP = (amendoim - 150 * E) / 50 < (branco - 750 * E) / 750 ? (amendoim - 150 * E) / 50 : (branco - 750 * E) / 750;
        
        // predileta
        for (P = 0; P <= maxP; P++) {
            // calcula ingredientes restantes
            long long restoAmendoim = amendoim - (150 * E + 50 * P);
            long long restoBranco = branco - (750 * E + 750 * P);
            long long restoLeite = leite - (600 * E + 700 * P);

            // sortidas
            if (restoAmendoim >= 0 && restoBranco >= 0 && restoLeite >= 0 &&
                restoAmendoim % 50 == 0 && restoBranco % 500 == 0 && restoLeite % 950 == 0) {
                S = restoAmendoim / 50;

                if (S >= 0 && (S * 500 == restoBranco) && (S * 950 == restoLeite)) {
                    printf("%lld %lld %lld\n", E, P, S);
                    return 0;
                }
            }
        }
    }
    return 0;
}
