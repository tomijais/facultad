void main(int vec[], int dim)
{
    int i, j, aux;
    for (int i = 0; i < dim; i++)
    {
        for (int i = 0; i < dim; i++)
        {
            if(vec[i] > vec[j]){
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}