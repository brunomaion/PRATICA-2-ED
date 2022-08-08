#ifndef NODE_HPP
#define NODE_HPP
template <typename TipoInfo>
// classe
class Node
{
private:
    TipoInfo dados;
    Node<TipoInfo> *proximo;

public:
    Node();  
    ~Node(); 

    TipoInfo getDados();
    void setDados(TipoInfo dados);
    Node<TipoInfo> *getProximo();
    void setProximo(Node<TipoInfo> *proximo);
};

template <typename TipoInfo>
Node<TipoInfo>::Node()
{
    dados = TipoInfo(0);
    proximo = nullptr;
}

template <typename TipoInfo>
Node<TipoInfo>::~Node()
{
    proximo = nullptr;
}

template <typename TipoInfo>
TipoInfo Node<TipoInfo>::getDados()
{
    return dados;
}
template <typename TipoInfo>
Node<TipoInfo> *Node<TipoInfo>::getProximo()
{
    return proximo;
}

template <typename TipoInfo>
void Node<TipoInfo>::setDados(TipoInfo dados)
{
    this->dados = dados;
}
template <typename TipoInfo>
void Node<TipoInfo>::setProximo(Node<TipoInfo> *proximo)
{
    this->proximo = proximo;
}
#endif
