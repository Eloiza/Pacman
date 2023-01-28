class Node{
    public:
        Node();
        Node(unsigned int x, unsigned int y);
        Node(unsigned int x, unsigned int y, double f);
        
        virtual ~Node() = default;
        
        bool operator<(Node const &n) const;
        bool operator>(Node const &n) const;
        bool operator==(Node const &n) const;

        unsigned int x;
        unsigned int y;
        double h;
        double g;
        double f;
};