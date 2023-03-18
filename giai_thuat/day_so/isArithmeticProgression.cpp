bool isArithmeticProgression(std::vector<int> sequence)
{
    if (sequence.size() == 1)
        return true;
    int k = sequence[1] - sequence[0];
    for (int i = 1; i < sequence.size(); i++)
        if (sequence[i]-sequence[i-1]!=k) 
            return false;
    return true;
}