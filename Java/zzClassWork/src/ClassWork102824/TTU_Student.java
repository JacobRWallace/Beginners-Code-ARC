package ClassWork102824;

public class TTU_Student implements TTU_St, TTU_St1{
    private String name;
    private double score;
    private boolean passfail;

    public void setname(String name) {this.name = name;}
    public String getname() {return name;}
    public void setscore(double score) {this.score = score;}
    public double getscore() {return score;}
    public void setpassfail(boolean pf) {passfail = pf;}
    public boolean getpassfail() {return passfail;}
}