public class NativeDoubleOp implements java.util.function.DoubleUnaryOperator, AutoCloseable{
    public NativeDoubleOp() {
    }

    private long nativeAddress=0;
    private boolean nativeDeleteOnClose=false;

    protected NativeDoubleOp(final long nativeAddress) {
        this.nativeAddress = nativeAddress;
    }
    private native void nativeDelete();

    @Override
    public synchronized void  close() {
        nativeDelete();
    }

    protected void finalizer() {
        close();
    }


    @Override
    native public double applyAsDouble(double param0);
}
