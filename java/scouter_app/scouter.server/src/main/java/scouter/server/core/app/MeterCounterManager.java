/*
 *  Copyright 2015 the original author or authors.
 *  @https://github.com/scouter-project/scouter
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

package scouter.server.core.app;

import scouter.util.LinkedMap;

/**
 * 
 * The MeterCounterManager class manages the meter counter objects and provides an interface to get the meter counter for a specified object and counter name.
 *
 * 
 * 
 */
public class MeterCounterManager {
    private static MeterCounterManager instance = new MeterCounterManager();

    private LinkedMap<Key, MeterCounter> meterCounterMap = new LinkedMap<Key, MeterCounter>().setMax(10000);

    /**
     * 
     * The Key class represents a unique key for a meter counter. It contains the object hash and counter name.
     * 
     */
    public static class Key {
        public int objHash;
        public String counterName;

        public Key(int objHash, String counterName) {
            this.objHash = objHash;
            this.counterName = counterName;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof Key) {
                Key k = (Key) obj;
                return this.objHash == ((Key) obj).objHash && this.counterName.equals(((Key) obj).counterName);
            }
            return false;
        }

        @Override
        public int hashCode() {
            return objHash ^ counterName.hashCode();
        }
    }

    /**
     * 
     * Returns the instance of MeterCounterManager.
     * 
     * @return the MeterCounterManager instance
     */
    public static MeterCounterManager getInstance() {
        return instance;
    }

    /**
     * 
     * Returns the meter counter object for the specified object hash and counter name. Creates a new meter counter object if it doesn't exist.
     * 
     * @param objHash the object hash
     * @param counterName the counter name
     * @return the meter counter object
     */
    public MeterCounter getMeterCounter(int objHash, String counterName) {
        Key key = new Key(objHash, counterName);
        MeterCounter meterCounter = meterCounterMap.get(key);

        if (meterCounter == null) {
            meterCounter = new MeterCounter();
            meterCounterMap.put(key, meterCounter);
        }

        return meterCounter;
    }
}