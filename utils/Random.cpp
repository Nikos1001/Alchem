
#include "Random.h"

namespace AlchemUtils {

    f32 Random::Val() {
        return (f32)rand() / (f32)RAND_MAX;
    }
}
