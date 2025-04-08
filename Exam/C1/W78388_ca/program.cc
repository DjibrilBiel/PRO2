#include <string>
#include <vector>
#include <queue>
using namespace std;

/**
 * @brief Simula un algorisme "Round Robin" en un vector de cues
 *
 * La funció itera circularment (és a dir, considerant l'element n-1 
 * com l'inmediatament anterior al 0) el vector de cues, i va afegint 
 * els elements que treu del capdavant de cada cua en una cua resultat.
 *
 * @param  queues  Les cues d'entrada
 *
 * @returns La cua resultant d'aplicar l'algorisme "Round Robin"
 */
queue<string> round_robin(vector<queue<string>>& queues) {
    queue<string> result;

    int max_size = 0;
    for (int i = 0; i < queues.size(); ++i)
        if (max_size < queues[i].size()) max_size = queues[i].size();

    for (int j = 0; j < max_size; ++j) {
        for (int i = 0; i < queues.size(); ++i) {
            if (not queues[i].empty()) {
                result.push(queues[i].front());
                queues[i].pop();
            }
        }
    }
    
    return result;
}