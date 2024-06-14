function minMovesToSeat(seats: number[], students: number[]): number {
    let freqSeats:number[] = [];
    let freqStudents:number[] = [];
    for(let i=0; i<students.length; i++){
        freqSeats[seats[i]] ? freqSeats[seats[i]]++ : freqSeats[seats[i]] = 1;
        freqStudents[students[i]] ? freqStudents[students[i]]++ : freqStudents[students[i]] = 1;
    }
    let i=0, j=0, ans = 0;
    while(i<101 && j<101){
        if(freqSeats[i] && freqStudents[j]){
            ans += Math.abs(i-j);
            freqStudents[j]--;
            freqSeats[i]--;
        }
        else if(freqSeats[i]){
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
};