package com.github.jmabuin.hashmaptest;

public class HashMapTestJava {

    public static void main(String[] args) {

        HashMapTestOptions newOptions = new HashMapTestOptions(args);

        switch (newOptions.getMode()) {
            case HASHMAP:
                HashMapRunner hashMapRunner = new HashMapRunner(newOptions);
                hashMapRunner.run();
                break;
            case GUAVA:
                GuavaRunner guavaRunner = new GuavaRunner(newOptions);
                guavaRunner.run();
                break;
            default:
                newOptions.printHelp();
                break;
        }

        System.exit(0);


    }


}
