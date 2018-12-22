#ifndef KMINT_ASESSMENT_PORT_H
#define KMINT_ASESSMENT_PORT_H

namespace kmint
{
    namespace pigisland
    {
        class Port
        {
        public:
            Port(int symbol, int minRecovery, int maxRecovery): symbol(symbol), minRecovery(minRecovery), maxRecovery(maxRecovery)
            {}

            int getSymbol() const
            {
                return symbol;
            }

            int getMinRecovery() const
            {
                return minRecovery;
            }

            int getMaxRecovery() const
            {
                return maxRecovery;
            }

        private:
            int symbol;
            int minRecovery;
            int maxRecovery;
        };
    }
}


#endif //KMINT_ASESSMENT_PORT_H
