class Node{
    public:
        Node();
        Node(unsigned int x, unsigned int y);
        Node(unsigned int x, unsigned int y, double f);
        Node(unsigned int x, unsigned int y, double f, char direction);

        virtual ~Node() = default;

        bool operator<(Node const &n) const;
        bool operator>(Node const &n) const;
        bool operator==(Node const &n) const;

        unsigned int x;
        unsigned int y;
        unsigned int parent_x;
        unsigned int parent_y;

        // double h;
        // double g;
        double f;
};