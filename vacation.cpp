int max_vacation(char *calender, int npto)
{
    // scan the calender char array using a window pointer.
    int max_nv = 0;
    char *window = calender;
    while (window && *window)
    {
        // employ a first workday pointer, which start from the window pointer, and a counter of vacations
        char *first_workday = window;
        int nv = 0;
        int tnpto = npto;
        while (tnpto > 0)
        {
            // move the first-workday-pointer forward until it finds the first workday, and count the holidays the pointer has passed.
            while (*first_workday == 'H')
            {
                first_workday++;
                nv++;
            }
            // try to turn the workday into pto.
            while (tnpto > 0 && *first_workday == 'W')
            {
                /* code */
                first_workday++;
                tnpto--;
                nv++;
            }
        } // repeat until all the pto days are used.
        // count the vacations around the PTO. If the number of vacation is larger than the previous one, remember it.
        if (max_nv < nv)
            max_nv = nv;
    } // move the window pointer to next one, repeat the above steps.
    return max_nv;
}