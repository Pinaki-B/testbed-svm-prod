float coefficients[3][3] = {{0.1384109244475858, -0.17580689040014794, 0.05305756007329051}, {-0.1238324332620836, 0.16217829287509716, -0.04417048022727365}, {-0.0038378824509298533, -0.004044456778298007, -0.0066206997748394685}};
float intercepts[3] = {-0.6654246180946659, -0.667771844051417, 0.6666516822019654};
volatile float features[3];


int predict (float features[]) {
    float class_val = -__FLT_MAX__;
    int class_idx = -1;
    int i, il, j, jl;
    for (i = 0, il = sizeof(coefficients) / sizeof (coefficients[0]); i < il; i++) {
        float prob = 0.;
        for (j = 0, jl = sizeof(coefficients[0]) / sizeof (coefficients[0][0]); j < jl; j++) {
            prob += coefficients[i][j] * features[j];
        }
        if (prob + intercepts[i] > class_val) {
            class_val = prob + intercepts[i];
            class_idx = i;
        }
    }
    return class_idx;
}

int main(int argc, const char * argv[]) {

    /* Features: */
    int i;
    for (i = 1; i < argc; i++) {
        features[i-1] = atof(argv[i]);
    }

    /* Prediction: */
    // printf("%d", predict(features));
    return predict(features);
}
