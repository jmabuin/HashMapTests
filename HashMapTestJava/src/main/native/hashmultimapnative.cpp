#include <unordered_map>
#include <vector>

#include "com_github_jmabuin_hashmaptest_HashMultiMapNative.h"

std::unordered_map<int, std::vector<int>> *myMap;
/*
 * Class:     com_github_jmabuin_hashmaptest_HashMultiMapNative
 * Method:    init
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_github_jmabuin_hashmaptest_HashMultiMapNative_init (JNIEnv *env, jobject jobj) {

    myMap = new std::unordered_map<int, std::vector<int>>();
    return 1;

}

/*
 * Class:     com_github_jmabuin_hashmaptest_HashMultiMapNative
 * Method:    add
 * Signature: (III)I
 */
JNIEXPORT jint JNICALL Java_com_github_jmabuin_hashmaptest_HashMultiMapNative_add (JNIEnv *env, jobject jobj, jint key, jint v1, jint v2) {

    std::unordered_map<int, std::vector<int>>::iterator it;

    int c_key = (int) key;
    it = myMap->find(c_key);

    if(it == myMap->end()) {


        myMap->insert(std::pair<int, std::vector<int>> (c_key, std::vector<int>()));

    }

    myMap->at(c_key).push_back((int) v1);
    myMap->at(c_key).push_back((int) v2);

    return myMap->size();

}

/*
 * Class:     com_github_jmabuin_hashmaptest_HashMultiMapNative
 * Method:    get
 * Signature: (I)[I
 */
JNIEXPORT jintArray JNICALL Java_com_github_jmabuin_hashmaptest_HashMultiMapNative_get (JNIEnv *env, jobject jobj, jint key) {

    int c_key = (int) key;

    auto sit = myMap->find(c_key);

    jintArray iarr = nullptr;

    int *foundValues;

    if(sit != myMap->end()) {

        iarr = env->NewIntArray(sit->second.size());
        foundValues = (int *)malloc(sizeof(int) * sit->second.size());

            int i = 0;

            for(i = 0; i< sit->second.size(); ++i) {
                //consume(pos);
                foundValues[i] = sit->second.at(i);
            }

            env->SetIntArrayRegion(iarr, 0, sit->second.size(), foundValues);
            free(foundValues);
        }

        return iarr;
}

/*
 * Class:     com_github_jmabuin_hashmaptest_HashMultiMapNative
 * Method:    size
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_github_jmabuin_hashmaptest_HashMultiMapNative_size (JNIEnv *env, jobject jobj) {

    return myMap->size();

}

