#ifndef crclj_fwd_h
#define crclj_fwd_h


namespace crclj {
    
    namespace java {
            namespace lang {
                class Object;
            } // end namespace lang;
    }// end namespace java 
    
   

    
 namespace java{
  namespace awt{
   class Component;
   class Container;
   class Window;
   class Frame;
  } // end namespace awt
 } // end namespace java

 namespace javax{
  namespace swing{
   class JFrame;
  } // end namespace swing
 } // end namespace javax

 namespace pvjscript{
  class Main;
 } // end namespace pvjscript

 namespace java{
  namespace awt{
   class Dialog;
  } // end namespace awt
 } // end namespace java

 namespace rcsdesign{
  class QueryDialog;
 } // end namespace rcsdesign

 namespace rcs{
  class RCS_VERSION;
  namespace posemath{
   class PM_CIRCLE;
   class PmQuaternion;
   class PM_QUATERNION;
   class PmRotationMatrix;
   class PmCircle;
  } // end namespace posemath
 } // end namespace rcs

 namespace java{
  namespace awt{
   namespace geom{
    class Point2D;
    class Point2DDouble;
   } // end namespace geom
  } // end namespace awt
 } // end namespace java

 namespace rcs{
  namespace posemath{
   class PmCartesian;
   class PmEulerZyz;
   class PM_EULER_ZYZ;
  } // end namespace posemath

  namespace nml{
   class NMLmsg;
   class NML_PERFORMANCE_TEST_MSG;
   class NMLConnection;
  } // end namespace nml
 } // end namespace rcs

 namespace javax{
  namespace swing{
   class JComponent;
   class JPanel;
  } // end namespace swing
 } // end namespace javax

 namespace diagapplet{
  namespace plotter{
   class ParseOptionsJPanel;
   class plotterJFrame;
   class ParseOptions;
   class PlotGraphScreenMap;
  } // end namespace plotter

  class PlotTracker;
  class HierarchyLoad_NB_UI;
 } // end namespace diagapplet

 namespace java{
  namespace awt{
   class Panel;
  } // end namespace awt

  namespace applet{
   class Applet;
  } // end namespace applet
 } // end namespace java

 namespace diagapplet{
  namespace CodeGen{
   class CodeGen;
  } // end namespace CodeGen
 } // end namespace diagapplet

 namespace java{
  namespace awt{
   class TextComponent;
   class TextArea;
  } // end namespace awt
 } // end namespace java

 namespace diagapplet{
  namespace CodeGen{
   class CodeGenTextAreaWrapper;
   class LoadHierarchyUpdateInterface;
   class DiagNMLFormatConvertErrCallback;
   class BufferInfo;
   class DefinedValue;
   class DiagNMLMsgDictCreator;
   class CodeGenTextFieldInterface;
   class CodeGenBellRingerInterface;
   class DiagNMLmsg;
  } // end namespace CodeGen
 } // end namespace diagapplet

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace analysis{
      namespace differentiation{
       class MultivariateDifferentiableVectorFunction;
       class UnivariateMatrixFunctionDifferentiator;
       class SparseGradient;
      } // end namespace differentiation

      namespace function{
       class Inverse;
       class Abs;
       class Rint;
       class Expm1;
       class Cosh;
       class Subtract;
      } // end namespace function

      namespace integration{
       namespace gauss{
        class BaseRuleFactory;
        class LegendreRuleFactory;
       } // end namespace gauss
      } // end namespace integration

      namespace solvers{
       class BaseAbstractUnivariateSolver;
       class AbstractUnivariateDifferentiableSolver;
       class AbstractUnivariateSolver;
       class BaseSecantSolver;
       class PegasusSolver;
      } // end namespace solvers

      namespace interpolation{
       class NevilleInterpolator;
       class PiecewiseBicubicSplineInterpolatingFunction;
       class SplineInterpolator;
      } // end namespace interpolation

      class DifferentiableUnivariateVectorFunction;
      class UnivariateFunction;
     } // end namespace analysis

     namespace ode{
      class AbstractIntegrator;
      namespace nonstiff{
       class RungeKuttaIntegrator;
       class EulerIntegrator;
      } // end namespace nonstiff

      namespace sampling{
       class AbstractStepInterpolator;
       class NordsieckStepInterpolator;
      } // end namespace sampling
     } // end namespace ode

     namespace optimization{
      namespace direct{
       class BaseAbstractMultivariateOptimizer;
      } // end namespace direct

      namespace general{
       class AbstractDifferentiableOptimizer;
      } // end namespace general

      namespace direct{
       class BaseAbstractMultivariateVectorOptimizer;
      } // end namespace direct

      namespace general{
       class AbstractLeastSquaresOptimizer;
       class GaussNewtonOptimizer;
      } // end namespace general

      namespace direct{
       class MultivariateFunctionPenaltyAdapter;
       class BaseAbstractMultivariateSimpleBoundsOptimizer;
       class CMAESOptimizer;
      } // end namespace direct

      namespace univariate{
       class UnivariatePointValuePair;
       class BracketFinder;
       class BaseAbstractUnivariateOptimizer;
       class UnivariateMultiStartOptimizer;
      } // end namespace univariate

      namespace linear{
       class LinearObjectiveFunction;
      } // end namespace linear
     } // end namespace optimization
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace lang{
   class Throwable;
   class Exception;
   class RuntimeException;
   class IllegalStateException;
  } // end namespace lang
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace exception{
      class MathIllegalStateException;
     } // end namespace exception

     namespace optimization{
      namespace linear{
       class NoFeasibleSolutionException;
       class SimplexTableau;
       class AbstractLinearOptimizer;
       class SimplexSolver;
       class LinearOptimizer;
      } // end namespace linear

      namespace fitting{
       class CurveFitter;
       class HarmonicFitter;
       class PolynomialFitter;
       class GaussianFitter;
      } // end namespace fitting

      class BaseMultivariateOptimizer;
      class BaseOptimizer;
      class ConvergenceChecker;
      class DifferentiableMultivariateOptimizer;
      class Target;
      class MultivariateDifferentiableOptimizer;
      class BaseMultivariateVectorOptimizer;
      class DifferentiableMultivariateVectorOptimizer;
      class AbstractConvergenceChecker;
      class MultivariateDifferentiableVectorOptimizer;
      class SimplePointChecker;
      class BaseMultivariateVectorMultiStartOptimizer;
      class DifferentiableMultivariateVectorMultiStartOptimizer;
     } // end namespace optimization

     namespace ml{
      namespace neuralnet{
       namespace twod{
        class NeuronSquareMesh2D;
       } // end namespace twod

       class UpdateAction;
       class Network;
       class Neuron;
       class FeatureInitializer;
       class MapUtils;
       class FeatureInitializerFactory;
      } // end namespace neuralnet

      namespace distance{
       class EuclideanDistance;
       class DistanceMeasure;
       class ManhattanDistance;
       class CanberraDistance;
       class EarthMoversDistance;
       class ChebyshevDistance;
      } // end namespace distance

      namespace clustering{
       namespace evaluation{
        class ClusterEvaluator;
        class SumOfClusterVariances;
       } // end namespace evaluation

       class Clusterer;
       class DBSCANClusterer;
       class KMeansPlusPlusClusterer;
      } // end namespace clustering
     } // end namespace ml

     namespace random{
      class RandomGenerator;
      class RandomVectorGenerator;
      class BitsStreamGenerator;
      class AbstractWell;
      class Well19937c;
      class RandomDataImpl;
      class HaltonSequenceGenerator;
      class CorrelatedRandomVectorGenerator;
      class NormalizedRandomGenerator;
      class AbstractRandomGenerator;
      class ISAACRandom;
      class GaussianRandomGenerator;
      class UnitSphereRandomVectorGenerator;
     } // end namespace random
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace util{
   class Random;
  } // end namespace util
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace random{
      class RandomAdaptor;
      class Well44497b;
     } // end namespace random

     namespace distribution{
      class AbstractRealDistribution;
     } // end namespace distribution

     namespace random{
      class EmpiricalDistribution;
      class Well19937a;
      class StableRandomGenerator;
     } // end namespace random

     namespace stat{
      namespace regression{
       class AbstractMultipleLinearRegression;
       class OLSMultipleLinearRegression;
       class MultipleLinearRegression;
      } // end namespace regression

      namespace descriptive{
       class AbstractUnivariateStatistic;
       class AbstractStorelessUnivariateStatistic;
       namespace moment{
        class StandardDeviation;
        class FirstMoment;
        class SecondMoment;
        class ThirdMoment;
        class FourthMoment;
       } // end namespace moment

       class DescriptiveStatistics;
      } // end namespace descriptive
     } // end namespace stat

     namespace complex{
      class RootsOfUnity;
     } // end namespace complex

     namespace dfp{
      class Dfp;
     } // end namespace dfp

     namespace optim{
      class BaseOptimizer;
      class BaseMultivariateOptimizer;
      namespace nonlinear{
       namespace vector{
        class MultivariateVectorOptimizer;
        class JacobianMultivariateVectorOptimizer;
       } // end namespace vector

       namespace scalar{
        class MultivariateOptimizer;
        class GradientMultivariateOptimizer;
        namespace gradient{
         class NonLinearConjugateGradientOptimizer;
        } // end namespace gradient

        namespace noderiv{
         class BOBYQAOptimizer;
        } // end namespace noderiv
       } // end namespace scalar
      } // end namespace nonlinear

      namespace univariate{
       class UnivariateOptimizer;
       class MultiStartUnivariateOptimizer;
       class SearchInterval;
      } // end namespace univariate

      class BaseMultiStartMultivariateOptimizer;
     } // end namespace optim

     namespace fraction{
      class BigFractionField;
     } // end namespace fraction

     namespace distribution{
      class LogNormalDistribution;
      class TriangularDistribution;
      class AbstractIntegerDistribution;
      class PoissonDistribution;
      class ChiSquaredDistribution;
     } // end namespace distribution

     namespace geometry{
      namespace partitioning{
       class BSPTreeVisitor;
      } // end namespace partitioning

      class VectorFormat;
     } // end namespace geometry
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace lang{
   class IllegalArgumentException;
  } // end namespace lang
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace exception{
      class MathIllegalArgumentException;
     } // end namespace exception

     namespace linear{
      class NonPositiveDefiniteOperatorException;
      class IterativeLinearSolver;
      class PreconditionedIterativeLinearSolver;
      class ConjugateGradient;
     } // end namespace linear

     namespace exception{
      class MathIllegalNumberException;
      class DimensionMismatchException;
     } // end namespace exception

     namespace linear{
      class NonSquareMatrixException;
      class AnyMatrix;
     } // end namespace linear

     namespace util{
      class CompositeFormat;
      class TransformerMap;
      class MultidimensionalCounter;
     } // end namespace util
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace crcl{
  namespace base{
   class DataThingType;
   class JointDetailsType;
   class JointSpeedAccelType;
   class CRCLCommandType;
   class MiddleCommandType;
   class SetIntermediatePoseToleranceType;
   class SetEndPoseToleranceType;
   class EndCanonType;
   class SetRobotParametersType;
  } // end namespace base
 } // end namespace crcl

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     class ByteOrderMark;
     namespace comparator{
      class AbstractFileComparator;
      class NameFileComparator;
      class ReverseComparator;
     } // end namespace comparator

     class FileCleaner;
     namespace filefilter{
      class AbstractFileFilter;
      class AgeFileFilter;
      class NotFileFilter;
      class WildcardFilter;
     } // end namespace filefilter
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace com{
  namespace siemens{
   namespace ct{
    namespace exi{
     namespace datatype{
      class AbstractDatatype;
      class AbstractBinaryDatatype;
      class BinaryHexDatatype;
      namespace charset{
       class AbstractRestrictedCharacterSet;
       class XSDBooleanCharacterSet;
       class XSDDoubleCharacterSet;
       class XSDIntegerCharacterSet;
      } // end namespace charset

      class Datatype;
      class DecimalDatatype;
      class FloatDatatype;
      class IntegerDatatype;
      class NBitUnsignedIntegerDatatype;
      class StringDatatype;
      namespace strings{
       class AbstractStringCoder;
       class StringEncoderImpl;
       class BoundedStringEncoderImpl;
       class StringDecoder;
       class StringEncoder;
      } // end namespace strings

      class UnsignedIntegerDatatype;
     } // end namespace datatype

     class EncodingOptions;
     namespace exceptions{
      class EXIException;
     } // end namespace exceptions

     class EXIBodyDecoder;
     class EXIFactory;
     class EXIStreamEncoder;
     class GrammarFactory;
     namespace grammars{
      namespace event{
       class AbstractEvent;
       class AttributeGeneric;
       class AttributeNS;
       class Comment;
       class DocType;
       class EndElement;
       class Event;
       class NamespaceDeclaration;
       class ProcessingInstruction;
       class SelfContained;
       class StartDocument;
       class StartElementGeneric;
       class StartElementNS;
      } // end namespace event
     } // end namespace grammars
    } // end namespace exi
   } // end namespace ct
  } // end namespace siemens
 } // end namespace com

 namespace org{
  namespace apache{
   namespace xerces{
    namespace impl{
     namespace xs{
      namespace models{
       class CMBuilder;
      } // end namespace models
     } // end namespace xs
    } // end namespace impl
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace com{
  namespace siemens{
   namespace ct{
    namespace exi{
     namespace grammars{
      class EXIContentModelBuilder;
      namespace grammar{
       class AbstractGrammar;
       class AbstractBuiltInGrammar;
       class BuiltInDocContent;
       class BuiltInFragmentContent;
       class AbstractSchemaInformedGrammar;
       class DocEnd;
       class Fragment;
       class SchemaInformedDocContent;
       class AbstractSchemaInformedContent;
       class SchemaInformedStartTag;
       class SchemaInformedFirstStartTag;
       class SchemaInformedStartTagGrammar;
      } // end namespace grammar

      namespace production{
       class AbstractProduction;
       class SchemaLessProduction;
      } // end namespace production

      class AbstractGrammars;
      class SchemaLessGrammars;
      class XSDGrammarsBuilder;
     } // end namespace grammars

     namespace values{
      class AbstractValue;
      class AbstractBinaryValue;
     } // end namespace values
    } // end namespace exi
   } // end namespace ct
  } // end namespace siemens
 } // end namespace com

 namespace org{
  namespace apache{
   namespace xerces{
    namespace dom{
     class NodeImpl;
     class ChildNode;
     class ParentNode;
     class ElementImpl;
    } // end namespace dom
   } // end namespace xerces

   namespace html{
    namespace dom{
     class HTMLElementImpl;
     class HTMLBodyElementImpl;
     class HTMLBuilder;
     class HTMLFieldSetElementImpl;
     class HTMLFontElementImpl;
     class HTMLFormControl;
     class HTMLIsIndexElementImpl;
    } // end namespace dom
   } // end namespace html

   namespace wml{
    class WMLCardElement;
    class WMLHeadElement;
    class WMLOptionElement;
    class WMLStrongElement;
    namespace dom{
     class WMLElementImpl;
     class WMLAElementImpl;
     class WMLDoElementImpl;
    } // end namespace dom
   } // end namespace wml

   namespace xerces{
    namespace dom{
     class ElementDefinitionImpl;
     class ElementNSImpl;
     class LCount;
     class NamedNodeMapImpl;
     class ObjectFactory;
     class CharacterDataImpl;
     class TextImpl;
     namespace events{
      class EventImpl;
      class UIEventImpl;
      class MouseEventImpl;
     } // end namespace events
    } // end namespace dom

    namespace impl{
     class Constants;
     class XMLNamespaceBinder;
     class XML11NamespaceBinder;
     class XMLScanner;
     class XMLDTDScannerImpl;
     class XMLEntityHandler;
     namespace xs{
      class AttributePSVImpl;
      class FilePathToURI;
      class SchemaGrammar;
      class XSAnnotationImpl;
      class XSAttributeGroupDecl;
      class XSConstraints;
      class XSElementDeclHelper;
      class XSGrammarBucket;
     } // end namespace xs
    } // end namespace impl

    namespace dom{
     class CoreDOMImplementationImpl;
     class DOMImplementationImpl;
     class PSVIDOMImplementationImpl;
    } // end namespace dom

    namespace impl{
     namespace xs{
      class XSImplementationImpl;
      class XSLoaderImpl;
      class XSModelGroupImpl;
      class XSNotationDecl;
      class XSParticleDecl;
      class XSWildcardDecl;
      namespace identity{
       class XPathMatcher;
      } // end namespace identity

      namespace models{
       class XSCMValidator;
      } // end namespace models
     } // end namespace xs
    } // end namespace impl

    namespace parsers{
     class XMLParser;
     class AbstractXMLDocumentParser;
     class AbstractSAXParser;
    } // end namespace parsers

    namespace util{
     class ParserConfigurationSettings;
    } // end namespace util

    namespace parsers{
     class XML11Configuration;
     class XPointerParserConfiguration;
    } // end namespace parsers

    namespace stax{
     class ImmutableLocation;
     namespace events{
      class XMLEventImpl;
      class CharactersImpl;
      class DTDImpl;
      class ElementImpl;
      class EndElementImpl;
      class AttributeImpl;
      class NamespaceImpl;
      class StartDocumentImpl;
     } // end namespace events
    } // end namespace stax

    namespace util{
     class AttributesProxy;
     class DefaultErrorHandler;
     class EntityResolver2Wrapper;
     class EntityResolverWrapper;
    } // end namespace util

    namespace xni{
     namespace parser{
      class XMLInputSource;
     } // end namespace parser
    } // end namespace xni

    namespace util{
     class HTTPInputSource;
     class MessageFormatter;
    } // end namespace util

    namespace xinclude{
     class XIncludeTextReader;
    } // end namespace xinclude

    namespace xni{
     class XMLDTDContentModelHandler;
     class XMLDocumentFragmentHandler;
     class XMLLocator;
     class XMLString;
     namespace grammars{
      class XMLGrammarLoader;
     } // end namespace grammars

     namespace parser{
      class XMLComponent;
      class XMLDTDContentModelSource;
      class XMLDTDSource;
      class XMLDocumentSource;
      class XMLErrorHandler;
      class XMLParserConfiguration;
     } // end namespace parser
    } // end namespace xni

    namespace xpointer{
     class XPointerErrorHandler;
     class XPointerPart;
    } // end namespace xpointer

    namespace xs{
     class AttributePSVI;
     class ItemPSVI;
     class StringList;
     class XSAttributeGroupDefinition;
     class XSConstants;
     class XSModelGroup;
     class XSObjectList;
     namespace datatypes{
      class ObjectList;
     } // end namespace datatypes
    } // end namespace xs
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace parsers{
    class ParserConfigurationException;
   } // end namespace parsers

   namespace stream{
    class XMLEventFactory;
    class XMLStreamException;
    namespace events{
     class EndElement;
     class XMLEvent;
    } // end namespace events
   } // end namespace stream

   namespace transform{
    class OutputKeys;
    class SecuritySupport;
   } // end namespace transform
  } // end namespace xml
 } // end namespace javax

 namespace java{
  namespace lang{
   class Error;
  } // end namespace lang
 } // end namespace java

 namespace javax{
  namespace xml{
   namespace transform{
    class TransformerFactoryConfigurationError;
    class TransformerFactory;
    namespace sax{
     class SAXTransformerFactory;
     class TemplatesHandler;
    } // end namespace sax
   } // end namespace transform

   namespace validation{
    class SchemaFactory;
    class TypeInfoProvider;
   } // end namespace validation

   namespace xpath{
    class XPathException;
    class XPathExpressionException;
    class XPathFunctionException;
   } // end namespace xpath
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace w3c{
   namespace dom{
    class CharacterData;
    class DOMImplementationList;
    class ElementTraversal;
    class ProcessingInstruction;
    namespace css{
     class CSSPrimitiveValue;
     class CSSValueList;
    } // end namespace css

    namespace events{
     class DocumentEvent;
    } // end namespace events

    namespace html{
     class HTMLAnchorElement;
     class HTMLCollection;
     class HTMLFormElement;
     class HTMLImageElement;
     class HTMLMenuElement;
     class HTMLParamElement;
     class HTMLTableColElement;
    } // end namespace html

    namespace ls{
     class LSException;
     class LSSerializer;
    } // end namespace ls

    namespace stylesheets{
     class StyleSheet;
    } // end namespace stylesheets

    namespace xpath{
     class XPathEvaluator;
    } // end namespace xpath
   } // end namespace dom
  } // end namespace w3c

  namespace xml{
   namespace sax{
    class ContentHandler;
    class DTDHandler;
    class SAXException;
    class SAXNotRecognizedException;
    namespace helpers{
     class DefaultHandler;
    } // end namespace helpers

    namespace ext{
     class DefaultHandler2;
     class EntityResolver2;
    } // end namespace ext
   } // end namespace sax
  } // end namespace xml
 } // end namespace org

 namespace crcl{
  namespace utils{
   class DefaultMain;
   class PoseToleranceChecker;
   class PendantClientOuterStub;
   class OverHeadJPanel;
  } // end namespace utils
 } // end namespace crcl

 namespace rcsdesign{
  class BackupLineData;
 } // end namespace rcsdesign

 namespace rcs{
  namespace posemath{
   class PmSpherical;
   class PM_SPHERICAL;
   class PM_XYA;
   class PmHomogeneous;
   class PM_HOMOGENEOUS;
   class PM_LINE;
   class PmException;
   class PM_ROTATION_MATRIX;
  } // end namespace posemath

  class ClassChooser;
  namespace nml{
   class NMLFormatConverter;
   class NMLFormatConverterBase;
   class XMLFormatConverter;
  } // end namespace nml
 } // end namespace rcs

 namespace diagapplet{
  class plotSetPreserve;
  class auxBufferPreserve;
  class LineInfo;
  namespace CodeGen{
   class STI_Tokenizer;
   class StringFuncs;
  } // end namespace CodeGen

  namespace utils{
   class URlLoadInfoFrame;
  } // end namespace utils
 } // end namespace diagapplet

 namespace java{
  namespace awt{
   class List;
  } // end namespace awt
 } // end namespace java

 namespace diagapplet{
  namespace utils{
   class CountList;
   class FakeFastListPanel;
   class CountButtonInterface;
   class SaveImage;
   class DiagError;
   class CountListInterface;
  } // end namespace utils

  class diagappletFrame;
 } // end namespace diagapplet

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace analysis{
      namespace function{
       class Sin;
       class Ceil;
       class Sinc;
      } // end namespace function

      namespace solvers{
       class UnivariateSolverUtils;
       class RiddersSolver;
       class AbstractPolynomialSolver;
       class BaseUnivariateSolver;
      } // end namespace solvers

      class DifferentiableMultivariateVectorFunction;
      class MultivariateVectorFunction;
     } // end namespace analysis

     namespace ode{
      namespace nonstiff{
       class ClassicalRungeKuttaIntegrator;
      } // end namespace nonstiff

      class JacobianMatrices;
      namespace events{
       class EventFilter;
       class EventState;
      } // end namespace events
     } // end namespace ode

     namespace optimization{
      namespace general{
       class AbstractScalarDifferentiableOptimizer;
       class NonLinearConjugateGradientOptimizer;
      } // end namespace general
     } // end namespace optimization

     namespace stat{
      namespace descriptive{
       namespace moment{
        class Variance;
       } // end namespace moment

       class SynchronizedDescriptiveStatistics;
       class StorelessUnivariateStatistic;
      } // end namespace descriptive
     } // end namespace stat

     namespace dfp{
      class UnivariateDfpFunction;
      class DfpMath;
     } // end namespace dfp

     namespace special{
      class Beta;
     } // end namespace special

     namespace filter{
      class MeasurementModel;
      class DefaultProcessModel;
     } // end namespace filter

     class RealFieldElement;
     class FieldElement;
     class Field;
     namespace optim{
      namespace nonlinear{
       namespace vector{
        namespace jacobian{
         class AbstractLeastSquaresOptimizer;
         class LevenbergMarquardtOptimizer;
        } // end namespace jacobian
       } // end namespace vector

       namespace scalar{
        namespace noderiv{
         class AbstractSimplex;
         class MultiDirectionalSimplex;
        } // end namespace noderiv

        class MultiStartMultivariateOptimizer;
        class ObjectiveFunction;
        class MultivariateFunctionMappingAdapter;
       } // end namespace scalar
      } // end namespace nonlinear

      class AbstractConvergenceChecker;
      namespace univariate{
       class SimpleUnivariateValueChecker;
       class BrentOptimizer;
       class UnivariatePointValuePair;
      } // end namespace univariate

      namespace linear{
       class SimplexTableau;
      } // end namespace linear

      class AbstractOptimizationProblem;
      class OptimizationData;
     } // end namespace optim

     namespace distribution{
      namespace fitting{
       class MultivariateNormalMixtureExpectationMaximization;
      } // end namespace fitting

      class UniformRealDistribution;
     } // end namespace distribution

     namespace geometry{
      namespace enclosing{
       class WelzlEncloser;
      } // end namespace enclosing

      namespace partitioning{
       class AbstractRegion;
      } // end namespace partitioning

      namespace euclidean{
       namespace threed{
        class PolyhedronsSet;
        class SubLine;
        class Vector3D;
       } // end namespace threed
      } // end namespace euclidean

      namespace partitioning{
       class RegionFactory;
       class Transform;
       class BoundaryProjection;
       class Hyperplane;
      } // end namespace partitioning
     } // end namespace geometry

     namespace linear{
      class RealLinearOperator;
      class AbstractRealMatrix;
      class DiagonalMatrix;
      class BlockRealMatrix;
      class RectangularCholeskyDecomposition;
      class FieldLUDecomposition;
      class FieldDecompositionSolver;
      class AbstractFieldMatrix;
      class JacobiPreconditioner;
      class NonSquareOperatorException;
      class FieldMatrix;
      class DefaultFieldMatrixChangingVisitor;
      class RealMatrixPreservingVisitor;
      class RealVector;
      class RealMatrix;
     } // end namespace linear

     namespace util{
      class Precision;
      class MedianOf3PivotingStrategy;
      class CentralPivotingStrategy;
      class PivotingStrategyInterface;
      class KthSelector;
      class FastMathCalc;
      class DoubleArray;
      class Decimal64Field;
      class FastMathLiteralArrays;
     } // end namespace util
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace crcl{
  namespace base{
   class CloseToolChangerType;
   class ParameterSettingType;
   class CRCLStatusType;
   class MoveScrewType;
   class MoveToType;
   class ObjectFactory;
   class PoseType;
   class PoseAndSetType;
   class TransAccelType;
   class TransAccelRelativeType;
   class DwellType;
   class SetLengthUnitsType;
   class OpenToolChangerType;
   class SetTransAccelType;
   class JointForceTorqueType;
   class PointType;
  } // end namespace base
 } // end namespace crcl

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace comparator{
      class LastModifiedFileComparator;
     } // end namespace comparator

     class EndianUtils;
     namespace filefilter{
      class AndFileFilter;
      class FileFilterUtils;
      class TrueFileFilter;
      class WildcardFileFilter;
     } // end namespace filefilter

     class FileSystemUtils;
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace io{
   class InputStream;
  } // end namespace io
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace input{
      class BoundedInputStream;
     } // end namespace input
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace io{
   class OutputStream;
  } // end namespace io
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace output{
      class WriterOutputStream;
     } // end namespace output

     class ThreadMonitor;
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace com{
  namespace siemens{
   namespace ct{
    namespace exi{
     namespace core{
      class AbstractEXIBodyCoder;
      class AbstractEXIBodyEncoder;
      class EXIBodyEncoderReordered;
     } // end namespace core

     namespace io{
      namespace channel{
       class AbstractEncoderChannel;
       class DecoderChannel;
      } // end namespace channel
     } // end namespace io

     class SchemaIdResolver;
     namespace types{
      class AbstractTypeCoder;
      class AbstractTypeEncoder;
      class TypeDecoder;
     } // end namespace types

     namespace util{
      class SimpleDocTypeParser;
     } // end namespace util
    } // end namespace exi
   } // end namespace ct
  } // end namespace siemens
 } // end namespace com

 namespace org{
  namespace apache{
   namespace html{
    namespace dom{
     class CollectionIndex;
    } // end namespace dom
   } // end namespace html

   namespace xerces{
    namespace dom{
     class CoreDocumentImpl;
     class DocumentImpl;
    } // end namespace dom
   } // end namespace xerces

   namespace html{
    namespace dom{
     class HTMLDocumentImpl;
     class HTMLFormElementImpl;
     class HTMLImageElementImpl;
    } // end namespace dom
   } // end namespace html

   namespace wml{
    class WMLBigElement;
    class WMLDocument;
    class WMLInputElement;
    class WMLPrevElement;
    class WMLTemplateElement;
    namespace dom{
     class WMLEmElementImpl;
     class WMLFieldsetElementImpl;
     class WMLHeadElementImpl;
    } // end namespace dom
   } // end namespace wml

   namespace xerces{
    namespace dom{
     class PSVIDocumentImpl;
     class ProcessingInstructionImpl;
    } // end namespace dom
   } // end namespace xerces
  } // end namespace apache

  namespace w3c{
   namespace dom{
    namespace ranges{
     class RangeException;
    } // end namespace ranges
   } // end namespace dom
  } // end namespace w3c

  namespace apache{
   namespace xerces{
    namespace dom{
     class RangeExceptionImpl;
     class SecuritySupport;
     class TreeWalkerImpl;
     namespace events{
      class MutationEventImpl;
     } // end namespace events
    } // end namespace dom

    namespace impl{
     class ExternalSubsetResolver;
     class Version;
     class XML11DTDScannerImpl;
     class XMLEntityScanner;
     class XML11EntityScanner;
     class XMLDocumentFragmentScannerImpl;
     class XMLDocumentScannerImpl;
     namespace dtd{
      class DTDGrammarBucket;
      class XMLDTDValidator;
      class XML11DTDValidator;
      class XMLAttributeDecl;
      class XMLContentSpec;
      class XMLDTDProcessor;
      class XMLDTDLoader;
     } // end namespace dtd

     namespace dv{
      namespace xs{
       class TypeValidator;
       class EntityDV;
      } // end namespace xs
     } // end namespace dv
    } // end namespace impl
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace io{
   class Reader;
  } // end namespace io
 } // end namespace java

 namespace org{
  namespace apache{
   namespace xerces{
    namespace impl{
     namespace io{
      class Latin1Reader;
      class UTF8Reader;
     } // end namespace io

     namespace xs{
      namespace identity{
       class Field;
       class ValueStore;
      } // end namespace identity

      namespace models{
       class XSAllCM;
      } // end namespace models
     } // end namespace xs

     namespace dtd{
      namespace models{
       class CMNode;
      } // end namespace models
     } // end namespace dtd

     namespace xs{
      namespace models{
       class XSCMLeaf;
      } // end namespace models
     } // end namespace xs
    } // end namespace impl

    namespace jaxp{
     namespace validation{
      class XMLSchemaValidatorComponentManager;
     } // end namespace validation
    } // end namespace jaxp

    namespace xs{
     class XSModelGroupDefinition;
     class XSParticle;
     namespace datatypes{
      class XSDateTime;
     } // end namespace datatypes
    } // end namespace xs
   } // end namespace xerces

   namespace xml{
    namespace serialize{
     class DOMSerializerImpl;
     class Printer;
     class IndentPrinter;
     class LineSeparator;
     class Method;
     class ObjectFactory;
     class BaseMarkupSerializer;
     class HTMLSerializer;
     class XHTMLSerializer;
     class XMLSerializer;
     class XML11Serializer;
    } // end namespace serialize
   } // end namespace xml
  } // end namespace apache

  namespace w3c{
   namespace dom{
    namespace html{
     class HTMLDOMImplementation;
    } // end namespace html
   } // end namespace dom
  } // end namespace w3c
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace parsers{
    class FactoryFinder;
    class SecuritySupport;
   } // end namespace parsers

   namespace stream{
    class XMLOutputFactory;
    namespace events{
     class NotationDeclaration;
    } // end namespace events

    namespace util{
     class XMLEventConsumer;
    } // end namespace util
   } // end namespace stream

   namespace transform{
    class TransformerException;
    class TransformerConfigurationException;
    namespace sax{
     class SAXResult;
    } // end namespace sax

    namespace stream{
     class StreamResult;
    } // end namespace stream
   } // end namespace transform

   namespace validation{
    class SchemaFactoryLoader;
   } // end namespace validation

   namespace xpath{
    class XPathFactoryFinder;
   } // end namespace xpath
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace w3c{
   namespace dom{
    class DOMErrorHandler;
    class DocumentFragment;
    class Node;
    namespace css{
     class CSSPageRule;
     class CSSValue;
     class ViewCSS;
    } // end namespace css

    namespace events{
     class UIEvent;
    } // end namespace events

    namespace html{
     class HTMLButtonElement;
     class HTMLFontElement;
     class HTMLIFrameElement;
     class HTMLMapElement;
     class HTMLParagraphElement;
     class HTMLTableCellElement;
    } // end namespace html

    namespace ls{
     class DOMImplementationLS;
     class LSResourceResolver;
    } // end namespace ls

    namespace stylesheets{
     class MediaList;
    } // end namespace stylesheets

    namespace views{
     class DocumentView;
    } // end namespace views
   } // end namespace dom
  } // end namespace w3c

  namespace xml{
   namespace sax{
    class Attributes;
    class Locator;
    namespace helpers{
     class LocatorImpl;
    } // end namespace helpers

    namespace ext{
     class Locator2Impl;
    } // end namespace ext
   } // end namespace sax
  } // end namespace xml
 } // end namespace org

 namespace crcl{
  namespace utils{
   class CRCLPosemath;
   class XpathUtils;
   class ListChooserJPanel;
   class LauncherJFrame;
   class SimulatedKinematicsPlausible;
   class GripperJFrame;
  } // end namespace utils
 } // end namespace crcl

 namespace rcsdesign{
  class FileTypeInfo;
  class rcsdesignModuleInfo;
  class AutoSizedTextArea;
  class MakeFileRunner;
 } // end namespace rcsdesign

 namespace diagapplet{
  namespace utils{
   class StandAloneApplet;
  } // end namespace utils
 } // end namespace diagapplet

 namespace rcsdesign{
  class rcsDesignGui;
 } // end namespace rcsdesign

 namespace rcs{
  namespace posemath{
   class PmEulerZyx;
   class PmCylindrical;
   class LineFitTester;
   class PM_EULER_ZYX;
   class PmRotationVector;
   class PM_ROTATION_VECTOR;
  } // end namespace posemath

  namespace nml{
   class errlogMsgDict;
   class nmlperf;
   class XMLNodeInfo;
   class time_tracker;
   class NMLConnectionCreator;
   class RCS_STAT_MSG;
   class RCS_STAT_MSG_V2;
   class NMLBufferConfigInfo;
   class PackedFileReader;
   class NMLConnectionCreatorInterface;
   class DISPFormatConverter;
   class NMLFormatConvertErrCallbackInterface;
   class XMLFileWriter;
   class LogTimeEntry;
   class NMLSingleVarLogItem;
   class CMS_TIME;
   class NMLErrorAppender;
  } // end namespace nml

  namespace utils{
   class StrToInt;
   class CorrectedPipedInputStreamInterface;
   class StrToLong;
  } // end namespace utils
 } // end namespace rcs

 namespace diagapplet{
  namespace plotter{
   class PlotData;
  } // end namespace plotter
 } // end namespace diagapplet

 namespace javax{
  namespace swing{
   class AbstractCellEditor;
  } // end namespace swing
 } // end namespace javax

 namespace diagapplet{
  namespace plotter{
   class ColorEditor;
   class plotter_NB_UI;
  } // end namespace plotter

  class MessageFileJFrame;
  class HierarchyPanel;
  namespace CodeGen{
   class CodeGenCommon;
  } // end namespace CodeGen

  namespace utils{
   class FastListPanelInterface;
   class ModifiedFileDialog;
   class WatchVarEditor;
  } // end namespace utils
 } // end namespace diagapplet

 namespace com{
  namespace github{
   namespace wshackle{
    namespace poselist3dplot{
     class FXMLController;
    } // end namespace poselist3dplot
   } // end namespace wshackle
  } // end namespace github
 } // end namespace com

 namespace javafx{
  namespace application{
   class Application;
  } // end namespace application
 } // end namespace javafx

 namespace com{
  namespace github{
   namespace wshackle{
    namespace poselist3dplot{
     class MainApp1;
     class MainJFrame;
    } // end namespace poselist3dplot
   } // end namespace wshackle
  } // end namespace github
 } // end namespace com

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace fitting{
      namespace leastsquares{
       class EvaluationRmsChecker;
       class MultivariateJacobianFunction;
       class ParameterValidator;
       class LeastSquaresBuilder;
       class LeastSquaresFactory;
      } // end namespace leastsquares

      class CurveFitter;
      class AbstractCurveFitter;
      class GaussianCurveFitter;
      class PolynomialCurveFitter;
      class GaussianFitter;
      class HarmonicCurveFitter;
     } // end namespace fitting

     namespace analysis{
      namespace polynomials{
       class PolynomialFunction;
       class PolynomialsUtils;
      } // end namespace polynomials

      namespace differentiation{
       class UnivariateDifferentiableFunction;
       class DerivativeStructure;
       class MultivariateDifferentiableFunction;
      } // end namespace differentiation

      namespace integration{
       namespace gauss{
        class HermiteRuleFactory;
       } // end namespace gauss

       class BaseAbstractUnivariateIntegrator;
       class IterativeLegendreGaussIntegrator;
       class UnivariateIntegrator;
       class MidPointIntegrator;
       class LegendreGaussIntegrator;
      } // end namespace integration

      namespace solvers{
       class UnivariateDifferentiableSolver;
       class NewtonRaphsonSolver;
       class AbstractDifferentiableUnivariateSolver;
      } // end namespace solvers

      class BivariateFunction;
     } // end namespace analysis

     namespace ode{
      namespace nonstiff{
       class AdamsNordsieckTransformer;
      } // end namespace nonstiff

      namespace sampling{
       class StepNormalizer;
       class DummyStepHandler;
      } // end namespace sampling
     } // end namespace ode

     namespace ml{
      namespace neuralnet{
       namespace sofm{
        namespace util{
         class QuasiSigmoidDecayFunction;
        } // end namespace util
       } // end namespace sofm

       namespace oned{
        class NeuronString;
       } // end namespace oned
      } // end namespace neuralnet
     } // end namespace ml

     namespace stat{
      namespace descriptive{
       namespace moment{
        class VectorialCovariance;
       } // end namespace moment

       class WeightedEvaluation;
       class UnivariateStatistic;
      } // end namespace descriptive

      namespace ranking{
       class NaturalRanking;
      } // end namespace ranking

      namespace interval{
       class BinomialConfidenceInterval;
      } // end namespace interval
     } // end namespace stat

     namespace optim{
      namespace nonlinear{
       namespace scalar{
        namespace noderiv{
         class PowellOptimizer;
        } // end namespace noderiv

        class LeastSquaresConverter;
       } // end namespace scalar
      } // end namespace nonlinear

      namespace univariate{
       class BracketFinder;
      } // end namespace univariate

      class SimpleValueChecker;
     } // end namespace optim
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace text{
   class Format;
   class NumberFormat;
  } // end namespace text
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace fraction{
      class AbstractFormat;
      class BigFractionFormat;
      class ProperBigFractionFormat;
     } // end namespace fraction

     namespace exception{
      class ConvergenceException;
     } // end namespace exception

     namespace fraction{
      class FractionConversionException;
     } // end namespace fraction
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace lang{
   class Number;
  } // end namespace lang
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace fraction{
      class BigFraction;
     } // end namespace fraction

     namespace distribution{
      class LevyDistribution;
      class GumbelDistribution;
      class CauchyDistribution;
     } // end namespace distribution

     namespace geometry{
      namespace partitioning{
       class BSPTree;
      } // end namespace partitioning
     } // end namespace geometry

     namespace linear{
      class SymmLQ;
      class LUDecomposition;
      class IllConditionedOperatorException;
      class Array2DRowFieldMatrix;
      class NonSymmetricMatrixException;
      class CholeskyDecomposition;
     } // end namespace linear
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace util{
   class EventObject;
  } // end namespace util
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace util{
      class IterationEvent;
     } // end namespace util

     namespace linear{
      class IterativeLinearSolverEvent;
      class DefaultRealMatrixPreservingVisitor;
      class BlockFieldMatrix;
      class Array2DRowRealMatrix;
      class DefaultFieldMatrixPreservingVisitor;
      class SingularMatrixException;
      class DecompositionSolver;
      class QRDecomposition;
      class RealVectorFormat;
      class FieldMatrixPreservingVisitor;
      class FieldVector;
      class NonSelfAdjointOperatorException;
      class FieldMatrixChangingVisitor;
      class RealVectorChangingVisitor;
      class RealVectorPreservingVisitor;
      class RealMatrixChangingVisitor;
     } // end namespace linear

     namespace exception{
      class MultiDimensionMismatchException;
     } // end namespace exception

     namespace linear{
      class MatrixDimensionMismatchException;
     } // end namespace linear
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace crcl{
  namespace base{
   class RotAccelType;
   class ActuateJointsType;
   class MessageType;
   class TransAccelAbsoluteType;
   class TransSpeedType;
   class TransSpeedRelativeType;
   class RunProgramType;
  } // end namespace base
 } // end namespace crcl

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     class Charsets;
     namespace comparator{
      class PathFileComparator;
      class SizeFileComparator;
     } // end namespace comparator

     namespace filefilter{
      class CanWriteFileFilter;
      class HiddenFileFilter;
      class RegexFileFilter;
     } // end namespace filefilter

     class HexDump;
     namespace output{
      class ThresholdingOutputStream;
     } // end namespace output
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace com{
  namespace siemens{
   namespace ct{
    namespace exi{
     namespace api{
      namespace dom{
       class DOMBuilder;
      } // end namespace dom
     } // end namespace api

     namespace types{
      class TypedTypeEncoder;
     } // end namespace types
    } // end namespace exi
   } // end namespace ct
  } // end namespace siemens
 } // end namespace com

 namespace org{
  namespace xml{
   namespace sax{
    namespace helpers{
     class XMLFilterImpl;
    } // end namespace helpers
   } // end namespace sax
  } // end namespace xml
 } // end namespace org

 namespace com{
  namespace siemens{
   namespace ct{
    namespace exi{
     namespace util{
      class SkipRootElementXMLReader;
     } // end namespace util

     namespace values{
      class BinaryHexValue;
      class DateTimeValue;
      class IntegerValue;
     } // end namespace values
    } // end namespace exi
   } // end namespace ct
  } // end namespace siemens
 } // end namespace com

 namespace org{
  namespace apache{
   namespace html{
    namespace dom{
     class HTMLAppletElementImpl;
     class HTMLBRElementImpl;
     class HTMLDOMImplementationImpl;
     class HTMLIFrameElementImpl;
     class HTMLOListElementImpl;
    } // end namespace dom
   } // end namespace html

   namespace wml{
    class WMLElement;
    class WMLEmElement;
    class WMLNoopElement;
    class WMLSelectElement;
    class WMLTrElement;
    namespace dom{
     class WMLBrElementImpl;
     class WMLCardElementImpl;
     class WMLImgElementImpl;
     class WMLInputElementImpl;
     class WMLMetaElementImpl;
     class WMLNoopElementImpl;
     class WMLOneventElementImpl;
     class WMLOptgroupElementImpl;
     class WMLOptionElementImpl;
     class WMLPElementImpl;
     class WMLPostfieldElementImpl;
     class WMLPrevElementImpl;
     class WMLRefreshElementImpl;
     class WMLSelectElementImpl;
     class WMLSetvarElementImpl;
     class WMLSmallElementImpl;
     class WMLStrongElementImpl;
     class WMLTableElementImpl;
     class WMLTdElementImpl;
     class WMLTemplateElementImpl;
     class WMLTimerElementImpl;
     class WMLTrElementImpl;
     class WMLUElementImpl;
     class WMLWmlElementImpl;
    } // end namespace dom
   } // end namespace wml

   namespace xerces{
    namespace dom3{
     namespace as{
      class ASAttributeDeclaration;
      class ASContentModel;
      class ASDataType;
      class ASElementDeclaration;
      class ASEntityDeclaration;
      class ASModel;
      class ASNamedObjectMap;
      class ASNotationDeclaration;
      class ASObject;
      class ASObjectList;
      class CharacterDataEditAS;
      class DOMASBuilder;
      class DOMASException;
      class DOMASWriter;
      class DOMImplementationAS;
      class DocumentAS;
      class DocumentEditAS;
      class ElementEditAS;
      class NodeEditAS;
     } // end namespace as
    } // end namespace dom3

    namespace dom{
     class ASDOMImplementationImpl;
     class ASModelImpl;
     class AttrImpl;
     class AttrNSImpl;
     class AttributeMap;
     class CDATASectionImpl;
     class CommentImpl;
     class DOMConfigurationImpl;
     class DOMErrorImpl;
     class DOMImplementationListImpl;
     class DOMImplementationSourceImpl;
     class DOMInputImpl;
     class DOMLocatorImpl;
     class DOMMessageFormatter;
     class DOMNormalizer;
     class DOMOutputImpl;
     class DOMStringListImpl;
     class DOMXSImplementationSourceImpl;
     class DeepNodeListImpl;
     class DeferredAttrImpl;
     class DeferredAttrNSImpl;
     class DeferredCDATASectionImpl;
     class DeferredCommentImpl;
     class DeferredDOMImplementationImpl;
     class DeferredDocumentImpl;
     class DocumentTypeImpl;
     class DeferredDocumentTypeImpl;
     class DeferredElementDefinitionImpl;
     class DeferredElementImpl;
     class DeferredElementNSImpl;
     class EntityImpl;
     class DeferredEntityImpl;
     class EntityReferenceImpl;
     class DeferredEntityReferenceImpl;
     class DeferredNode;
     class NotationImpl;
     class DeferredNotationImpl;
     class DeferredProcessingInstructionImpl;
     class DeferredTextImpl;
     class DocumentFragmentImpl;
    } // end namespace dom

    namespace impl{
     namespace dtd{
      class XMLNSDTDValidator;
     } // end namespace dtd

     namespace dv{
      class SchemaDVFactory;
      namespace xs{
       class BaseSchemaDVFactory;
       class ExtendedSchemaDVFactoryImpl;
      } // end namespace xs
     } // end namespace dv

     namespace validation{
      class ValidationState;
      class ConfigurableValidationState;
     } // end namespace validation

     namespace xpath{
      namespace regex{
       class CaseInsensitiveMap;
      } // end namespace regex
     } // end namespace xpath

     namespace xs{
      class XSAttributeDecl;
      class XSAttributeUseImpl;
      class XSComplexTypeDecl;
     } // end namespace xs
    } // end namespace impl

    namespace util{
     class XMLResourceIdentifierImpl;
    } // end namespace util

    namespace impl{
     namespace xs{
      class XSDDescription;
      class XSDeclarationPool;
      class XSElementDecl;
      class XSGroupDecl;
      class XSMessageFormatter;
     } // end namespace xs
    } // end namespace impl
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace util{
   class AbstractCollection;
   class AbstractList;
  } // end namespace util
 } // end namespace java

 namespace org{
  namespace apache{
   namespace xerces{
    namespace impl{
     namespace xs{
      class XSModelImpl;
      namespace identity{
       class IdentityConstraint;
      } // end namespace identity

      namespace models{
       class XSCMRepeatingLeaf;
      } // end namespace models

      namespace traversers{
       class XSDAbstractTraverser;
       class XSDAbstractParticleTraverser;
       class XSDAttributeGroupTraverser;
       class XSDAttributeTraverser;
       class XSDGroupTraverser;
       class XSDAbstractIDConstraintTraverser;
       class XSDKeyrefTraverser;
       class XSDNotationTraverser;
       class XSDUniqueOrKeyTraverser;
       class XSDWildcardTraverser;
       class XSDocumentInfo;
      } // end namespace traversers

      namespace util{
       class ShortListImpl;
       class SimpleLocator;
       class XInt;
      } // end namespace util
     } // end namespace xs
    } // end namespace impl

    namespace util{
     class XMLGrammarPoolImpl;
    } // end namespace util

    namespace impl{
     namespace xs{
      namespace util{
       class XSGrammarPool;
      } // end namespace util
     } // end namespace xs
    } // end namespace impl
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace util{
   class AbstractMap;
  } // end namespace util
 } // end namespace java

 namespace org{
  namespace apache{
   namespace xerces{
    namespace impl{
     namespace xs{
      namespace util{
       class XSNamedMapImpl;
       class XSNamedMap4Types;
      } // end namespace util
     } // end namespace xs
    } // end namespace impl

    namespace jaxp{
     class DefaultValidationErrorHandler;
    } // end namespace jaxp
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace parsers{
    class DocumentBuilderFactory;
   } // end namespace parsers
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace apache{
   namespace xerces{
    namespace jaxp{
     class DocumentBuilderFactoryImpl;
     class JAXPConstants;
     class TeeXMLDocumentFilterImpl;
     class JAXPValidatorComponent;
    } // end namespace jaxp
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace parsers{
    class SAXParser;
   } // end namespace parsers
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace apache{
   namespace xerces{
    namespace jaxp{
     class SAXParserImpl;
     class UnparsedEntityHandler;
     namespace datatype{
      class SerializedDuration;
     } // end namespace datatype
    } // end namespace jaxp
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace datatype{
    class XMLGregorianCalendar;
   } // end namespace datatype
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace apache{
   namespace xerces{
    namespace jaxp{
     namespace datatype{
      class XMLGregorianCalendarImpl;
     } // end namespace datatype
    } // end namespace jaxp
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace validation{
    class Schema;
   } // end namespace validation
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace apache{
   namespace xerces{
    namespace jaxp{
     namespace validation{
      class AbstractXMLSchema;
      class EmptyXMLSchema;
      class ReadOnlyGrammarPool;
     } // end namespace validation
    } // end namespace jaxp

    namespace parsers{
     class AbstractDOMParser;
    } // end namespace parsers

    namespace util{
     class ErrorHandlerProxy;
     class ErrorHandlerWrapper;
     class JAXPNamespaceContextWrapper;
     class NamespaceSupport;
    } // end namespace util

    namespace xinclude{
     class MultipleScopeNamespaceSupport;
     class XIncludeNamespaceSupport;
    } // end namespace xinclude

    namespace xs{
     class XSComplexTypeDefinition;
     class XSModel;
     class XSObject;
     namespace datatypes{
      class ByteList;
     } // end namespace datatypes
    } // end namespace xs
   } // end namespace xerces

   namespace xml{
    namespace serialize{
     class DOMSerializer;
     class SecuritySupport;
    } // end namespace serialize
   } // end namespace xml
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace datatype{
    class Duration;
   } // end namespace datatype

   namespace stream{
    class FactoryConfigurationError;
    class XMLReporter;
    namespace events{
     class Characters;
     class Comment;
     class ProcessingInstruction;
    } // end namespace events
   } // end namespace stream

   namespace transform{
    class ErrorListener;
    namespace sax{
     class TransformerHandler;
    } // end namespace sax

    namespace stax{
     class StAXResult;
    } // end namespace stax
   } // end namespace transform

   namespace validation{
    class ValidatorHandler;
   } // end namespace validation

   namespace xpath{
    class XPath;
   } // end namespace xpath
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace w3c{
   namespace dom{
    class DOMException;
    class Element;
    class Notation;
    namespace bootstrap{
     class DOMImplementationRegistry;
    } // end namespace bootstrap

    namespace css{
     class Counter;
    } // end namespace css

    namespace events{
     class Event;
    } // end namespace events

    namespace html{
     class HTMLAppletElement;
     class HTMLDListElement;
     class HTMLFrameElement;
     class HTMLInputElement;
     class HTMLMetaElement;
     class HTMLPreElement;
     class HTMLTableElement;
    } // end namespace html

    namespace ls{
     class LSInput;
     class LSSerializerFilter;
    } // end namespace ls

    namespace stylesheets{
     class StyleSheetList;
    } // end namespace stylesheets

    namespace xpath{
     class XPathException;
    } // end namespace xpath
   } // end namespace dom
  } // end namespace w3c

  namespace xml{
   namespace sax{
    class Parser;
    namespace helpers{
     class AttributesImpl;
    } // end namespace helpers

    namespace ext{
     class Attributes2Impl;
    } // end namespace ext

    namespace helpers{
     class XMLReaderAdapter;
    } // end namespace helpers
   } // end namespace sax
  } // end namespace xml
 } // end namespace org

 namespace crcl{
  namespace utils{
   class PerfTest;
  } // end namespace utils
 } // end namespace crcl

 namespace rcsdesign{
  class rcsDesignUserAbortException;
  class ListElement;
  class AlertDialog;
  class QueryStringDialog;
  class Merger;
 } // end namespace rcsdesign

 namespace rcs{
  namespace posemath{
   class PmLine;
  } // end namespace posemath

  namespace nml{
   class RCS_CMD_MSG;
   class NMLException;
   class NMLConnectionInterface;
   class NML_ERROR;
   class NMLConfigInfo;
   class perftypeMsgDict;
  } // end namespace nml

  namespace utils{
   class SimpleFileFilter;
   class rcs_states;
   class CorrectedPipedInputStream;
  } // end namespace utils
 } // end namespace rcs

 namespace javax{
  namespace swing{
   class JLabel;
  } // end namespace swing
 } // end namespace javax

 namespace diagapplet{
  namespace plotter{
   class ColorRenderer;
   class StatsTextJFrame;
  } // end namespace plotter

  class diagappletJFrame;
  class plotTrackerPreserve;
  class diag_NB_UI;
  namespace CodeGen{
   class info_array_elem_info;
   class ModuleInfoInterface;
   class C_Generator;
  } // end namespace CodeGen

  namespace utils{
   class URLLoadInfoJPanel;
   class DiagErrorAppendInterface;
  } // end namespace utils
 } // end namespace diagapplet

 namespace javax{
  namespace swing{
   namespace table{
    class AbstractTableModel;
   } // end namespace table
  } // end namespace swing
 } // end namespace javax

 namespace diagapplet{
  namespace utils{
   class WatchTableModel;
   class FastListContainer;
   class WatchJPanel;
   class ImageJPanel;
   class WatchVar;
   class ImagePainter;
  } // end namespace utils
 } // end namespace diagapplet

 namespace com{
  namespace github{
   namespace wshackle{
    namespace poselist3dplot{
     class Track;
     class TrackPoint;
     class CsvParseOptions;
     class Scene3DController;
     class TrackUtils;
    } // end namespace poselist3dplot
   } // end namespace wshackle
  } // end namespace github
 } // end namespace com

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace fitting{
      namespace leastsquares{
       class LeastSquaresProblem;
       class LeastSquaresOptimizer;
       class OptimumImpl;
       class AbstractEvaluation;
       class DenseWeightedEvaluation;
       class LeastSquaresAdapter;
       class LevenbergMarquardtOptimizer;
       class GaussNewtonOptimizer;
       class ValueAndJacobianFunction;
      } // end namespace leastsquares

      class PolynomialFitter;
      class WeightedObservedPoint;
      class WeightedObservedPoints;
      class SimpleCurveFitter;
      class HarmonicFitter;
     } // end namespace fitting

     namespace analysis{
      namespace polynomials{
       class PolynomialSplineFunction;
       class PolynomialFunctionNewtonForm;
       class PolynomialFunctionLagrangeForm;
      } // end namespace polynomials

      namespace differentiation{
       class DSCompiler;
       class UnivariateVectorFunctionDifferentiator;
       class UnivariateDifferentiableMatrixFunction;
       class JacobianFunction;
       class GradientFunction;
       class FiniteDifferencesDifferentiator;
      } // end namespace differentiation

      namespace function{
       class Acos;
       class Logistic;
       class Log1p;
       class Multiply;
       class Constant;
       class Cbrt;
       class Logit;
       class HarmonicOscillator;
       class Log10;
       class Sinh;
       class Ulp;
       class Max;
      } // end namespace function

      namespace solvers{
       class DifferentiableUnivariateSolver;
       class SecantSolver;
      } // end namespace solvers

      namespace interpolation{
       class AkimaSplineInterpolator;
      } // end namespace interpolation

      class DifferentiableUnivariateMatrixFunction;
     } // end namespace analysis

     namespace ode{
      namespace nonstiff{
       class AdaptiveStepsizeIntegrator;
      } // end namespace nonstiff

      class MultistepIntegrator;
      namespace nonstiff{
       class AdamsIntegrator;
       class AdamsMoultonIntegrator;
       class RungeKuttaStepInterpolator;
       class HighamHall54StepInterpolator;
      } // end namespace nonstiff

      namespace sampling{
       class StepInterpolator;
      } // end namespace sampling
     } // end namespace ode

     namespace optimization{
      namespace general{
       class LevenbergMarquardtOptimizer;
      } // end namespace general

      namespace direct{
       class SimplexOptimizer;
       class BOBYQAOptimizer;
      } // end namespace direct

      namespace linear{
       class LinearConstraint;
       class UnboundedSolutionException;
      } // end namespace linear

      namespace fitting{
       class WeightedObservedPoint;
      } // end namespace fitting
     } // end namespace optimization

     namespace util{
      class Pair;
     } // end namespace util

     namespace optimization{
      class PointValuePair;
      class OptimizationData;
      class BaseMultivariateMultiStartOptimizer;
      class PointVectorValuePair;
      class BaseMultivariateSimpleBoundsOptimizer;
      class MultivariateOptimizer;
      class DifferentiableMultivariateMultiStartOptimizer;
     } // end namespace optimization

     namespace stat{
      namespace descriptive{
       class MultivariateSummaryStatistics;
      } // end namespace descriptive
     } // end namespace stat

     namespace complex{
      class ComplexUtils;
     } // end namespace complex

     namespace dfp{
      class BracketingNthOrderBrentSolverDFP;
      class DfpDec;
     } // end namespace dfp

     namespace special{
      class Gamma;
     } // end namespace special

     namespace primes{
      class Primes;
      class PollardRho;
     } // end namespace primes

     namespace filter{
      class DefaultMeasurementModel;
      class ProcessModel;
      class KalmanFilter;
     } // end namespace filter

     namespace optim{
      namespace nonlinear{
       namespace vector{
        namespace jacobian{
         class GaussNewtonOptimizer;
        } // end namespace jacobian

        class Target;
        class ModelFunctionJacobian;
        class ModelFunction;
       } // end namespace vector

       namespace scalar{
        namespace noderiv{
         class NelderMeadSimplex;
         class SimplexOptimizer;
        } // end namespace noderiv

        class ObjectiveFunctionGradient;
        class MultivariateFunctionPenaltyAdapter;
        class LineSearch;
       } // end namespace scalar
      } // end namespace nonlinear

      namespace linear{
       class LinearConstraintSet;
      } // end namespace linear

      class OptimizationProblem;
     } // end namespace optim

     namespace geometry{
      namespace spherical{
       namespace oned{
        class Arc;
       } // end namespace oned
      } // end namespace spherical

      namespace partitioning{
       class AbstractSubHyperplane;
      } // end namespace partitioning

      namespace spherical{
       namespace oned{
        class SubLimitAngle;
        class Sphere1D;
       } // end namespace oned

       namespace twod{
        class EdgesBuilder;
        class PropertiesComputer;
        class SphericalPolygonsSet;
        class SubCircle;
        class S2Point;
        class Circle;
        class Vertex;
        class Edge;
        class Sphere2D;
       } // end namespace twod
      } // end namespace spherical

      namespace enclosing{
       class EnclosingBall;
       class SupportBallGenerator;
      } // end namespace enclosing

      namespace euclidean{
       namespace threed{
        class SphericalCoordinates;
        class Plane;
        class Vector3DFormat;
        class Euclidean3D;
        class Rotation;
        class FieldRotation;
       } // end namespace threed

       namespace twod{
        class Vector2DFormat;
        class PolygonsSet;
        class SubLine;
        class Vector2D;
       } // end namespace twod

       namespace oned{
        class Interval;
        class Vector1D;
       } // end namespace oned
      } // end namespace euclidean

      namespace partitioning{
       namespace utilities{
        class AVLTree;
       } // end namespace utilities

       class BoundaryProjector;
       class InsideFinder;
      } // end namespace partitioning

      class Point;
      class Space;
     } // end namespace geometry

     namespace linear{
      class SingularOperatorException;
      class EigenDecomposition;
      class RRQRDecomposition;
     } // end namespace linear

     namespace exception{
      namespace util{
       class DummyLocalizable;
      } // end namespace util
     } // end namespace exception

     namespace util{
      class Combinations;
      class OpenIntToFieldHashMap;
      class IterationListener;
      class NumberTransformer;
      class FastMath;
      class Incrementor;
     } // end namespace util
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace crcl{
  namespace base{
   class RotSpeedType;
   class GripperStatusType;
   class SetTransSpeedType;
   class SetForceUnitsType;
   class RotAccelRelativeType;
  } // end namespace base
 } // end namespace crcl

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace filefilter{
      class EmptyFileFilter;
      class FalseFileFilter;
      class FileFileFilter;
      class PrefixFileFilter;
     } // end namespace filefilter

     class FileUtils;
     namespace input{
      class ReaderInputStream;
      class ReversedLinesFileReader;
     } // end namespace input
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace io{
   class FilterInputStream;
  } // end namespace io
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace input{
      class ProxyInputStream;
      class SwappedDataInputStream;
      class Tailer;
      class XmlStreamReader;
     } // end namespace input

     class LineIterator;
     namespace monitor{
      class FileAlterationListener;
      class FileAlterationListenerAdaptor;
      class FileAlterationMonitor;
      class FileAlterationObserver;
      class FileEntry;
     } // end namespace monitor

     namespace output{
      class BrokenOutputStream;
      class ByteArrayOutputStream;
     } // end namespace output
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace io{
   class FilterOutputStream;
  } // end namespace io
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace output{
      class ProxyOutputStream;
      class CountingOutputStream;
     } // end namespace output
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace io{
   class Writer;
  } // end namespace io
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace output{
      class FileWriterWithEncoding;
     } // end namespace output
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace io{
   class FilterWriter;
  } // end namespace io
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace output{
      class ProxyWriter;
     } // end namespace output
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace com{
  namespace siemens{
   namespace ct{
    namespace exi{
     namespace core{
      class AbstractEXIHeader;
      class EXIHeaderEncoder;
     } // end namespace core

     namespace grammars{
      namespace event{
       class StartElement;
      } // end namespace event

      namespace grammar{
       class AbstractBuiltInContent;
       class BuiltInElement;
       class BuiltInGrammar;
       class BuiltInStartTag;
       class Document;
       class Grammar;
       class SchemaInformedElement;
       class SchemaInformedFirstStartTagGrammar;
       class SchemaInformedFragmentContent;
       class SchemaInformedGrammar;
      } // end namespace grammar

      class Grammars;
      namespace production{
       class Production;
       class SchemaInformedProduction;
      } // end namespace production

      class SchemaInformedGrammars;
     } // end namespace grammars

     namespace helpers{
      class DefaultErrorHandler;
      class DefaultEXIFactory;
      class DefaultSchemaIdResolver;
     } // end namespace helpers

     namespace io{
      class BitInputStream;
      class BitOutputStream;
      namespace channel{
       class AbstractDecoderChannel;
       class BitDecoderChannel;
       class BitEncoderChannel;
       class ByteEncoderChannel;
      } // end namespace channel
     } // end namespace io

     namespace types{
      class AbstractTypeDecoder;
      class TypedTypeDecoder;
     } // end namespace types

     namespace util{
      class SkipRootElementXMLEventReader;
     } // end namespace util

     namespace values{
      class BinaryBase64Value;
      class BooleanValue;
      class DecimalValue;
      class FloatValue;
      class ListValue;
      class QNameValue;
      class StringValue;
      class Value;
     } // end namespace values
    } // end namespace exi
   } // end namespace ct
  } // end namespace siemens
 } // end namespace com

 namespace org{
  namespace apache{
   namespace xerces{
    namespace impl{
     namespace xpath{
      namespace regex{
       class RegularExpression;
       class EXIRegularExpression;
      } // end namespace regex
     } // end namespace xpath
    } // end namespace impl
   } // end namespace xerces

   namespace html{
    namespace dom{
     class HTMLAnchorElementImpl;
     class HTMLButtonElementImpl;
     class HTMLCollectionImpl;
     class HTMLHtmlElementImpl;
     class HTMLTitleElementImpl;
     class ObjectFactory;
     class SecuritySupport;
    } // end namespace dom
   } // end namespace html

   namespace wml{
    class WMLAnchorElement;
    class WMLFieldsetElement;
    class WMLOneventElement;
    class WMLSetvarElement;
    class WMLUElement;
   } // end namespace wml

   namespace xerces{
    namespace impl{
     namespace dtd{
      class XMLElementDecl;
      class XMLNotationDecl;
      namespace models{
       class CMAny;
       class CMLeaf;
       class ContentModelValidator;
       class MixedContentModel;
      } // end namespace models
     } // end namespace dtd

     namespace dv{
      class DVFactoryException;
      class DatatypeValidator;
      class DatatypeException;
      class InvalidDatatypeValueException;
      class SecuritySupport;
      class DTDDVFactory;
      namespace dtd{
       class DTDDVFactoryImpl;
       class NMTOKENDatatypeValidator;
       class XML11DTDDVFactoryImpl;
      } // end namespace dtd

      namespace xs{
       class FloatDV;
       class BaseDVFactory;
       class FullDVFactory;
       class DecimalDV;
       class IntegerDV;
       class AbstractDateTimeDV;
       class MonthDV;
       class QNameDV;
       class YearMonthDV;
      } // end namespace xs
     } // end namespace dv

     namespace validation{
      class EntityState;
      class ValidationManager;
     } // end namespace validation

     namespace xpath{
      namespace regex{
       class Op;
       class RegexParser;
       class ParserForXMLSchema;
       class REUtil;
       class Token;
       class RangeToken;
      } // end namespace regex
     } // end namespace xpath

     namespace xs{
      class ElementPSVImpl;
      class SchemaSymbols;
      class XMLSchemaLoader;
      namespace models{
       class XSEmptyCM;
      } // end namespace models

      namespace opti{
       class DefaultNode;
       class NodeImpl;
       class AttrImpl;
       class DefaultElement;
       class DefaultText;
       class DefaultXMLDocumentHandler;
       class NamedNodeMapImpl;
       class DefaultDocument;
       class SchemaDOM;
      } // end namespace opti
     } // end namespace xs
    } // end namespace impl

    namespace parsers{
     class BasicParserConfiguration;
    } // end namespace parsers

    namespace impl{
     namespace xs{
      namespace opti{
       class SchemaParsingConfig;
      } // end namespace opti

      namespace traversers{
       class Container;
       class SmallContainer;
       class StAXSchemaParser;
       class XSDElementTraverser;
       class XSDHandler;
      } // end namespace traversers
     } // end namespace xs
    } // end namespace impl

    namespace jaxp{
     namespace datatype{
      class DurationImpl;
     } // end namespace datatype

     namespace validation{
      class DOMResultBuilder;
      class DraconianErrorHandler;
      class JAXPValidationMessageFormatter;
      class SimpleXMLSchema;
      class StAXDocumentHandler;
      class StAXEventResultBuilder;
      class StreamValidatorHelper;
      class WeakReferenceXMLSchema;
     } // end namespace validation
    } // end namespace jaxp

    namespace parsers{
     class CachingParserPool;
     class DOMParser;
     class DTDConfiguration;
     class XMLGrammarParser;
     class DTDParser;
     class StandardParserConfiguration;
     class IntegratedParserConfiguration;
     class ObjectFactory;
     class XIncludeAwareParserConfiguration;
     class SecurityConfiguration;
     class SoftReferenceSymbolTableConfiguration;
     class XIncludeParserConfiguration;
     class XML11DTDConfiguration;
     class XML11NonValidatingConfiguration;
    } // end namespace parsers

    namespace stax{
     class DefaultNamespaceContext;
     class XMLEventFactoryImpl;
     namespace events{
      class EntityDeclarationImpl;
      class NotationDeclarationImpl;
     } // end namespace events
    } // end namespace stax

    namespace util{
     class AugmentationsImpl;
     class DOMErrorHandlerWrapper;
     class DOMUtil;
     class IntStack;
     class LocatorProxy;
    } // end namespace util

    namespace xinclude{
     class XIncludeMessageFormatter;
    } // end namespace xinclude

    namespace xni{
     class Augmentations;
     class NamespaceContext;
     class QName;
     class XMLAttributes;
     class XMLDTDHandler;
     class XMLDocumentHandler;
     namespace grammars{
      class Grammar;
      class XMLDTDDescription;
      class XMLGrammarPool;
      class XSGrammar;
     } // end namespace grammars

     namespace parser{
      class XMLComponentManager;
      class XMLDTDContentModelFilter;
      class XMLDTDFilter;
      class XMLDocumentFilter;
      class XMLDocumentScanner;
      class XMLPullParserConfiguration;
     } // end namespace parser
    } // end namespace xni

    namespace xpointer{
     class ShortHandPointer;
     class XPointerMessageFormatter;
     class XPointerProcessor;
    } // end namespace xpointer

    namespace xs{
     class ElementPSVI;
     class LSInputList;
     class PSVIProvider;
     class XSAnnotation;
     class XSIDCDefinition;
     class XSNamespaceItem;
     class XSTypeDefinition;
     namespace datatypes{
      class XSFloat;
     } // end namespace datatypes
    } // end namespace xs
   } // end namespace xerces

   namespace xml{
    namespace serialize{
     class OutputFormat;
     class SerializerFactory;
    } // end namespace serialize
   } // end namespace xml
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace stream{
    class FactoryFinder;
    class XMLEventReader;
    class XMLStreamReader;
    namespace events{
     class EntityDeclaration;
    } // end namespace events

    namespace util{
     class EventReaderDelegate;
    } // end namespace util
   } // end namespace stream

   namespace transform{
    class Result;
    class Source;
    class URIResolver;
   } // end namespace transform

   namespace validation{
    class SecuritySupport;
   } // end namespace validation

   namespace xpath{
    class XPathFunction;
   } // end namespace xpath
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace w3c{
   namespace dom{
    class DOMImplementation;
    class DocumentType;
    class NodeList;
    namespace css{
     class CSSImportRule;
     class CSSStyleRule;
     class ElementCSSInlineStyle;
    } // end namespace css

    namespace events{
     class EventTarget;
    } // end namespace events

    namespace html{
     class HTMLBaseElement;
     class HTMLDocument;
     class HTMLHeadElement;
     class HTMLLabelElement;
     class HTMLObjectElement;
     class HTMLOptGroupElement;
     class HTMLStyleElement;
     class HTMLTitleElement;
    } // end namespace html

    namespace traversal{
     class NodeIterator;
    } // end namespace traversal

    namespace xpath{
     class XPathNamespace;
    } // end namespace xpath
   } // end namespace dom
  } // end namespace w3c

  namespace xml{
   namespace sax{
    class ErrorHandler;
    class SAXParseException;
    namespace ext{
     class LexicalHandler;
    } // end namespace ext

    namespace helpers{
     class NamespaceSupport;
    } // end namespace helpers
   } // end namespace sax
  } // end namespace xml
 } // end namespace org

 namespace crcl{
  namespace utils{
   class SimServerOuterStub;
   class SimServerOuter;
   class SimServerInner;
   class MultiLineStringJPanel;
   class ObjTableJPanel;
  } // end namespace utils
 } // end namespace crcl

 namespace pvjscript{
  class ProcessView;
 } // end namespace pvjscript

 namespace rcsdesign{
  class rcsDesign;
 } // end namespace rcsdesign

 namespace rcs{
  namespace posemath{
   class PmPose;
   class PM_POSE;
   class PmRpy;
   class PM_CYLINDRICAL;
   class PM_CARTESIAN;
  } // end namespace posemath

  namespace nml{
   class MsgToTimeStamp;
  } // end namespace nml
 } // end namespace rcs

 namespace java{
  namespace net{
   class DatagramSocket;
  } // end namespace net
 } // end namespace java

 namespace rcs{
  namespace nml{
   class NonBlockingDatagramSocket;
   class NMLMessageDictionary;
   class XDRFormatConverter;
   class debugInfo;
   class PackedFileWriter;
   class NML_TEXT;
   class NML_DISPLAY;
   class NMLSingleVarLog;
  } // end namespace nml

  namespace utils{
   class CorrectedPipedOutputStream;
   class CorrectedPipedOutputStreamInterface;
   class CorrectedPipeData;
   class StackTracePrinter;
  } // end namespace utils
 } // end namespace rcs

 namespace diagapplet{
  class diag_NB_UI_ConnectToAll_Status;
  namespace plotter{
   class PlotGraphJPanel;
  } // end namespace plotter

  class diagPreserve;
  namespace CodeGen{
   class StructureTypeInfo;
   class CodeGenFrame;
   class ServerInfo;
  } // end namespace CodeGen

  namespace utils{
   class ImageJFrame;
  } // end namespace utils
 } // end namespace diagapplet

 namespace com{
  namespace github{
   namespace wshackle{
    namespace poselist3dplot{
     class View3DPlotJPanel;
     class CsvParseOptionsJPanel;
    } // end namespace poselist3dplot
   } // end namespace wshackle
  } // end namespace github
 } // end namespace com

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace analysis{
      namespace solvers{
       class BrentSolver;
       class NewtonSolver;
      } // end namespace solvers

      namespace interpolation{
       class LinearInterpolator;
       class TricubicFunction;
       class TricubicInterpolatingFunction;
       class MultivariateInterpolator;
       class BicubicSplineFunction;
       class BicubicSplineInterpolator;
       class SmoothingPolynomialBicubicSplineInterpolator;
       class TricubicSplineInterpolatingFunction;
      } // end namespace interpolation

      class UnivariateMatrixFunction;
      class ParametricUnivariateFunction;
     } // end namespace analysis

     namespace ode{
      namespace nonstiff{
       class EulerStepInterpolator;
      } // end namespace nonstiff
     } // end namespace ode

     namespace optimization{
      class MultivariateDifferentiableVectorMultiStartOptimizer;
     } // end namespace optimization

     namespace ml{
      namespace neuralnet{
       namespace sofm{
        class NeighbourhoodSizeFunction;
        class KohonenTrainingTask;
       } // end namespace sofm
      } // end namespace neuralnet

      namespace clustering{
       class Clusterable;
       class Cluster;
       class CentroidCluster;
       class MultiKMeansPlusPlusClusterer;
       class DoublePoint;
       class FuzzyKMeansClusterer;
      } // end namespace clustering
     } // end namespace ml

     namespace random{
      class RandomData;
      class RandomDataGenerator;
      class SobolSequenceGenerator;
      class JDKRandomGenerator;
      class RandomGeneratorFactory;
      class Well1024a;
      class ValueServer;
      class UncorrelatedRandomVectorGenerator;
      class Well44497a;
      class UniformRandomGenerator;
      class SynchronizedRandomGenerator;
      class MersenneTwister;
      class Well512a;
     } // end namespace random

     namespace stat{
      namespace regression{
       class ModelSpecificationException;
       class UpdatingMultipleLinearRegression;
       class RegressionResults;
       class MillerUpdatingRegression;
      } // end namespace regression

      namespace inference{
       class TTest;
       class ChiSquareTest;
       class GTest;
       class BinomialTest;
      } // end namespace inference

      namespace descriptive{
       namespace summary{
        class SumOfLogs;
        class SumOfSquares;
       } // end namespace summary

       namespace rank{
        class Min;
        class Percentile;
        class Median;
       } // end namespace rank

       class SummaryStatistics;
       class SynchronizedSummaryStatistics;
       class StatisticalSummary;
      } // end namespace descriptive
     } // end namespace stat

     namespace complex{
      class Quaternion;
     } // end namespace complex

     namespace optim{
      namespace nonlinear{
       namespace scalar{
        namespace noderiv{
         class CMAESOptimizer;
        } // end namespace noderiv
       } // end namespace scalar
      } // end namespace nonlinear

      namespace univariate{
       class UnivariateObjectiveFunction;
      } // end namespace univariate

      namespace linear{
       class UnboundedSolutionException;
       class LinearOptimizer;
       class SimplexSolver;
      } // end namespace linear

      class SimpleBounds;
      class InitialGuess;
      class MaxIter;
      class MaxEval;
      class SimplePointChecker;
      class SimpleVectorValueChecker;
      class PointVectorValuePair;
     } // end namespace optim

     namespace fraction{
      class FractionFormat;
      class ProperFractionFormat;
     } // end namespace fraction

     namespace geometry{
      namespace hull{
       class ConvexHullGenerator;
       class ConvexHull;
      } // end namespace hull

      namespace spherical{
       namespace oned{
        class ArcsSet;
        class S1Point;
        class LimitAngle;
       } // end namespace oned
      } // end namespace spherical
     } // end namespace geometry

     namespace exception{
      namespace util{
       class Localizable;
       class ExceptionContextProvider;
      } // end namespace util
     } // end namespace exception

     namespace util{
      class Decimal64;
      class MathUtils;
      class BigReal;
      class MathArrays;
     } // end namespace util
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace crcl{
  namespace base{
   class CRCLProgramType;
   class VectorType;
   class SetEndEffectorType;
   class SetTorqueUnitsType;
   class ConfigureJointReportType;
   class SetRotAccelType;
   class SetAngleUnitsType;
   class CommandStatusType;
   class RotSpeedRelativeType;
   class RotAccelAbsoluteType;
   class SetMotionCoordinationType;
   class ActuateJointType;
  } // end namespace base
 } // end namespace crcl

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace comparator{
      class CompositeFileComparator;
     } // end namespace comparator

     class CopyUtils;
     class FileDeleteStrategy;
     namespace filefilter{
      class DelegateFileFilter;
      class MagicNumberFileFilter;
      class SuffixFileFilter;
     } // end namespace filefilter

     namespace output{
      class CloseShieldOutputStream;
      class DeferredFileOutputStream;
      class TaggedOutputStream;
     } // end namespace output
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace com{
  namespace siemens{
   namespace ct{
    namespace exi{
     namespace api{
      namespace dom{
       class SaxToDomHandler;
      } // end namespace dom

      namespace sax{
       class SAXEncoder;
       class SAXEncoderExtendedHandler;
       class SAXHandler;
      } // end namespace sax

      namespace stream{
       class StAXDecoder;
      } // end namespace stream
     } // end namespace api

     namespace attributes{
      class AbstractAttributeList;
      class AttributeListSchemaInformed;
     } // end namespace attributes

     class Constants;
     namespace context{
      class AbstractUriContext;
      class GrammarContext;
      class GrammarUriContext;
      class UriContext;
     } // end namespace context

     namespace core{
      class AbstractEXIBodyDecoder;
      namespace container{
       class DocType;
       class NamespaceDeclaration;
       class PreReadValue;
       class ProcessingInstruction;
       class ValueAndDatatype;
      } // end namespace container

      class EXIBodyDecoderInOrder;
      class EXIBodyEncoderInOrder;
      class EXIBodyEncoderInOrderSC;
      class EXIHeaderDecoder;
     } // end namespace core

     namespace datatype{
      class BooleanDatatype;
      namespace charset{
       class CodePointCharacterSet;
       class RestrictedCharacterSet;
       class XSDDateTimeCharacterSet;
      } // end namespace charset
     } // end namespace datatype

     namespace types{
      class StringTypeDecoder;
      class StringTypeEncoder;
     } // end namespace types

     namespace util{
      class MethodsBag;
     } // end namespace util
    } // end namespace exi
   } // end namespace ct
  } // end namespace siemens
 } // end namespace com

 namespace org{
  namespace apache{
   namespace html{
    namespace dom{
     class HTMLAreaElementImpl;
     class HTMLDListElementImpl;
     class HTMLHeadingElementImpl;
     class HTMLLegendElementImpl;
     class HTMLLinkElementImpl;
     class HTMLMapElementImpl;
     class HTMLMenuElementImpl;
     class HTMLMetaElementImpl;
     class HTMLModElementImpl;
     class HTMLOptGroupElementImpl;
     class HTMLOptionElementImpl;
     class HTMLParagraphElementImpl;
     class HTMLParamElementImpl;
     class HTMLPreElementImpl;
     class HTMLQuoteElementImpl;
     class HTMLScriptElementImpl;
     class HTMLSelectElementImpl;
     class HTMLStyleElementImpl;
     class HTMLTableCaptionElementImpl;
     class HTMLTableCellElementImpl;
     class HTMLTableColElementImpl;
     class HTMLTableElementImpl;
     class HTMLTableRowElementImpl;
     class HTMLTableSectionElementImpl;
     class HTMLTextAreaElementImpl;
     class HTMLUListElementImpl;
     class NameNodeListImpl;
    } // end namespace dom
   } // end namespace html

   namespace wml{
    class WMLAElement;
    class WMLAccessElement;
    class WMLBElement;
    class WMLBrElement;
    class WMLGoElement;
    class WMLOptgroupElement;
    class WMLSmallElement;
    class WMLWmlElement;
    namespace dom{
     class WMLDOMImplementationImpl;
    } // end namespace dom
   } // end namespace wml

   namespace xerces{
    namespace dom{
     class NodeIteratorImpl;
     class NodeListCache;
     class PSVIAttrNSImpl;
     class PSVIElementNSImpl;
     class RangeImpl;
    } // end namespace dom

    namespace impl{
     class RevalidationHandler;
     class XML11DocumentScannerImpl;
     class XML11NSDocumentScannerImpl;
     class XMLEntityDescription;
     class XMLErrorReporter;
     class XMLNSDocumentScannerImpl;
     class XMLVersionDetector;
     namespace dtd{
      class DTDGrammar;
      class BalancedDTDGrammar;
      class XML11DTDProcessor;
      class XML11NSDTDValidator;
      class XMLDTDDescription;
      namespace models{
       class CMStateSet;
      } // end namespace models
     } // end namespace dtd

     namespace dv{
      class InvalidDatatypeFacetException;
      class ObjectFactory;
      class XSSimpleType;
      namespace dtd{
       class IDREFDatatypeValidator;
       class StringDatatypeValidator;
       class XML11NMTOKENDatatypeValidator;
      } // end namespace dtd

      namespace util{
       class HexBin;
      } // end namespace util

      namespace xs{
       class Base64BinaryDV;
       class DayDV;
       class DurationDV;
       class ListDV;
       class SchemaDateTimeException;
       class UnionDV;
       class XSSimpleTypeDelegate;
      } // end namespace xs
     } // end namespace dv

     namespace io{
      class ASCIIReader;
      class UCSReader;
     } // end namespace io

     namespace msg{
      class XMLMessageFormatter;
     } // end namespace msg

     namespace xpath{
      class XPath;
      namespace regex{
       class Match;
       class ParseException;
      } // end namespace regex
     } // end namespace xpath
    } // end namespace impl

    namespace xs{
     class XSElementDeclaration;
     class XSException;
     class XSMultiValueFacet;
     class XSSimpleTypeDefinition;
    } // end namespace xs
   } // end namespace xerces

   namespace xml{
    namespace serialize{
     class ElementState;
     class Serializer;
    } // end namespace serialize
   } // end namespace xml
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace datatype{
    class DatatypeFactory;
    class SecuritySupport;
   } // end namespace datatype

   namespace stream{
    class Location;
    class StreamFilter;
    class XMLStreamConstants;
    namespace events{
     class EndDocument;
     class StartElement;
    } // end namespace events
   } // end namespace stream

   namespace transform{
    class FactoryFinder;
    class SourceLocator;
    namespace dom{
     class DOMLocator;
    } // end namespace dom
   } // end namespace transform

   namespace validation{
    class Validator;
   } // end namespace validation

   namespace xpath{
    class XPathFactory;
   } // end namespace xpath
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace apache{
   namespace xmlcommons{
    class Version;
   } // end namespace xmlcommons
  } // end namespace apache

  namespace w3c{
   namespace dom{
    class Attr;
    class CDATASection;
    class DOMImplementationSource;
    class Entity;
    class Text;
    class TypeInfo;
    namespace css{
     class CSSCharsetRule;
     class CSSRule;
     class CSSRuleList;
     class DOMImplementationCSS;
    } // end namespace css

    namespace events{
     class EventException;
    } // end namespace events

    namespace html{
     class HTMLAreaElement;
     class HTMLDirectoryElement;
     class HTMLFrameSetElement;
     class HTMLIsIndexElement;
     class HTMLModElement;
     class HTMLQuoteElement;
     class HTMLTableRowElement;
     class HTMLTableSectionElement;
    } // end namespace html

    namespace ls{
     class LSOutput;
    } // end namespace ls

    namespace ranges{
     class Range;
    } // end namespace ranges

    namespace traversal{
     class NodeFilter;
    } // end namespace traversal

    namespace xpath{
     class XPathNSResolver;
    } // end namespace xpath
   } // end namespace dom
  } // end namespace w3c

  namespace xml{
   namespace sax{
    class EntityResolver;
    class SAXNotSupportedException;
    namespace helpers{
     class XMLReaderFactory;
    } // end namespace helpers
   } // end namespace sax
  } // end namespace xml
 } // end namespace org

 namespace rcsdesign{
  class rcsdesignFrame;
 } // end namespace rcsdesign

 namespace rcs{
  namespace posemath{
   class testpm;
   class PM_RPY;
  } // end namespace posemath
 } // end namespace rcs

 namespace diagapplet{
  class PainterInterface;
  namespace CodeGen{
   class CodeGenCommonInterface2;
   class STI_TokenizerInterface;
  } // end namespace CodeGen

  class diag_update_interface;
  namespace utils{
   class FastListPanel;
  } // end namespace utils
 } // end namespace diagapplet

 namespace java{
  namespace awt{
   class Button;
  } // end namespace awt
 } // end namespace java

 namespace diagapplet{
  namespace utils{
   class CountButton;
   class URLLoadInfoPanelInterface;
   class JListFastListPanel;
   class URLLoadInfoPanel;
   class fullScreenJPanelClass;
  } // end namespace utils

  class modulePreserve;
 } // end namespace diagapplet

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace analysis{
      namespace function{
       class Atanh;
       class Log;
       class Tanh;
       class Pow;
       class Asin;
       class Exp;
       class Signum;
      } // end namespace function

      namespace solvers{
       class LaguerreSolver;
      } // end namespace solvers

      namespace interpolation{
       class FieldHermiteInterpolator;
       class TricubicInterpolator;
       class BicubicFunction;
       class BicubicInterpolatingFunction;
       class BicubicInterpolator;
       class UnivariatePeriodicInterpolator;
       class MicrosphereInterpolator;
       class BicubicSplineInterpolatingFunction;
       class TricubicSplineFunction;
       class TrivariateGridInterpolator;
       class TricubicSplineInterpolator;
       class DividedDifferenceInterpolator;
       class HermiteInterpolator;
       class UnivariateInterpolator;
       class BivariateGridInterpolator;
      } // end namespace interpolation

      class TrivariateFunction;
      class FunctionUtils;
      class DifferentiableMultivariateFunction;
     } // end namespace analysis

     namespace ode{
      namespace nonstiff{
       class LutherStepInterpolator;
       class ThreeEighthesIntegrator;
       class GillStepInterpolator;
       class LutherIntegrator;
       class DormandPrince853StepInterpolator;
       class GillIntegrator;
       class MidpointStepInterpolator;
       class GraggBulirschStoerIntegrator;
       class ThreeEighthesStepInterpolator;
      } // end namespace nonstiff

      class ODEIntegrator;
      class FirstOrderDifferentialEquations;
      class SecondaryEquations;
      class Parameterizable;
      class ParameterizedODE;
      class MainStateJacobianProvider;
      class SecondOrderDifferentialEquations;
      class ParameterJacobianProvider;
      class ParameterizedWrapper;
      namespace sampling{
       class StepHandler;
      } // end namespace sampling
     } // end namespace ode

     namespace optimization{
      namespace general{
       class Preconditioner;
      } // end namespace general
     } // end namespace optimization

     namespace ml{
      namespace neuralnet{
       namespace sofm{
        class LearningFactorFunction;
        class KohonenUpdateAction;
       } // end namespace sofm
      } // end namespace neuralnet
     } // end namespace ml

     namespace stat{
      namespace regression{
       class SimpleRegression;
       class GLSMultipleLinearRegression;
      } // end namespace regression

      namespace inference{
       class KolmogorovSmirnovTest;
       class TestUtils;
       class OneWayAnova;
       class WilcoxonSignedRankTest;
       class MannWhitneyUTest;
      } // end namespace inference

      namespace descriptive{
       namespace summary{
        class Sum;
        class Product;
       } // end namespace summary

       namespace rank{
        class Max;
       } // end namespace rank

       namespace moment{
        class Kurtosis;
        class Skewness;
       } // end namespace moment

       class StatisticalSummaryValues;
       class StatisticalMultivariateSummary;
      } // end namespace descriptive

      namespace clustering{
       class DBSCANClusterer;
       class EuclideanIntegerPoint;
       class Clusterable;
       class Cluster;
      } // end namespace clustering

      namespace correlation{
       class KendallsCorrelation;
       class StorelessBivariateCovariance;
       class Covariance;
       class SpearmansCorrelation;
      } // end namespace correlation

      namespace interval{
       class IntervalUtils;
       class AgrestiCoullInterval;
       class WilsonScoreInterval;
       class ConfidenceInterval;
      } // end namespace interval

      class StatUtils;
      class Frequency;
     } // end namespace stat

     namespace genetics{
      class Chromosome;
      class AbstractListChromosome;
      class InvalidRepresentationException;
      class UniformCrossover;
      class OnePointCrossover;
      class BinaryChromosome;
      class FixedElapsedTime;
      class OrderedCrossover;
      class CycleCrossover;
      class RandomKey;
      class PermutationChromosome;
      class BinaryMutation;
      class ListPopulation;
      class ElitisticListPopulation;
      class SelectionPolicy;
      class TournamentSelection;
      class GeneticAlgorithm;
      class ChromosomePair;
      class CrossoverPolicy;
      class NPointCrossover;
      class RandomKeyMutation;
      class MutationPolicy;
      class Fitness;
      class Population;
      class StoppingCondition;
      class FixedGenerationCount;
     } // end namespace genetics

     namespace complex{
      class ComplexField;
      class Complex;
     } // end namespace complex

     namespace optim{
      namespace nonlinear{
       namespace scalar{
        namespace gradient{
         class Preconditioner;
        } // end namespace gradient
       } // end namespace scalar
      } // end namespace nonlinear

      namespace linear{
       class SolutionCallback;
      } // end namespace linear

      class ConvergenceChecker;
     } // end namespace optim

     namespace distribution{
      class EnumeratedRealDistribution;
      class EnumeratedIntegerDistribution;
      class ConstantRealDistribution;
      class GammaDistribution;
      class TDistribution;
      class LogisticDistribution;
      class LaplaceDistribution;
      class UniformIntegerDistribution;
      class HypergeometricDistribution;
      class AbstractMultivariateRealDistribution;
      class MultivariateNormalDistribution;
      class MixtureMultivariateRealDistribution;
      class MixtureMultivariateNormalDistribution;
      class MultivariateRealDistribution;
      class NakagamiDistribution;
      class IntegerDistribution;
     } // end namespace distribution

     namespace transform{
      class FastHadamardTransformer;
      class TransformUtils;
      class FastFourierTransformer;
      class RealTransformer;
      class FastSineTransformer;
     } // end namespace transform

     namespace geometry{
      namespace euclidean{
       namespace twod{
        class Line;
        class Segment;
        class Euclidean2D;
        class NestedLoops;
       } // end namespace twod

       namespace oned{
        class OrientedPoint;
        class Vector1DFormat;
        class IntervalsSet;
        class Euclidean1D;
        class SubOrientedPoint;
       } // end namespace oned
      } // end namespace euclidean

      namespace partitioning{
       namespace utilities{
        class OrderedTuple;
       } // end namespace utilities

       class BoundaryAttribute;
       class Characterization;
       class NodesSet;
       class Embedding;
       class BoundaryBuilder;
       class Region;
       class SubHyperplane;
      } // end namespace partitioning
     } // end namespace geometry

     namespace linear{
      class DefaultRealMatrixChangingVisitor;
      class SchurTransformer;
      class ArrayFieldVector;
      class RealMatrixFormat;
     } // end namespace linear

     namespace exception{
      namespace util{
       class ArgUtils;
      } // end namespace util

      class MathInternalError;
      class NotFiniteNumberException;
      class ZeroException;
      class NoBracketingException;
      class NotANumberException;
      class NonMonotonicSequenceException;
     } // end namespace exception
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace lang{
   class UnsupportedOperationException;
  } // end namespace lang
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace exception{
      class MathUnsupportedOperationException;
      class OutOfRangeException;
      class NumberIsTooSmallException;
      class NotPositiveException;
      class NotStrictlyPositiveException;
     } // end namespace exception
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace lang{
   class ArithmeticException;
  } // end namespace lang
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace exception{
      class MathArithmeticException;
      class NumberIsTooLargeException;
      class MaxCountExceededException;
      class TooManyIterationsException;
      class TooManyEvaluationsException;
      class NoDataException;
      class NullArgumentException;
     } // end namespace exception

     namespace util{
      class ContinuedFraction;
      class CombinatoricsUtils;
      class RandomPivotingStrategy;
      class BigRealField;
      class ArithmeticUtils;
      class ResizableDoubleArray;
      class OpenIntToDoubleHashMap;
      class DefaultTransformer;
      class IterationManager;
     } // end namespace util
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace crcl{
  namespace base{
   class TransSpeedAbsoluteType;
   class PoseToleranceType;
   class StopMotionType;
   class ConfigureJointReportsType;
   class CRCLCommandInstanceType;
   class SetRotSpeedType;
   class ParallelGripperStatusType;
   class SetEndEffectorParametersType;
   class ThreeFingerGripperStatusType;
  } // end namespace base
 } // end namespace crcl

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace comparator{
      class ExtensionFileComparator;
     } // end namespace comparator

     class DirectoryWalker;
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace io{
   class IOException;
  } // end namespace io
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     class FileExistsException;
     namespace filefilter{
      class DirectoryFileFilter;
      class NameFileFilter;
     } // end namespace filefilter

     namespace output{
      class ClosedOutputStream;
      class DemuxOutputStream;
      class LockableFileWriter;
     } // end namespace output

     class IOExceptionWithCause;
     class TaggedIOException;
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace com{
  namespace siemens{
   namespace ct{
    namespace exi{
     namespace api{
      namespace dom{
       class DOMWriter;
      } // end namespace dom

      namespace sax{
       class EXIResult;
      } // end namespace sax
     } // end namespace api
    } // end namespace exi
   } // end namespace ct
  } // end namespace siemens
 } // end namespace com

 namespace javax{
  namespace xml{
   namespace transform{
    namespace sax{
     class SAXSource;
    } // end namespace sax
   } // end namespace transform
  } // end namespace xml
 } // end namespace javax

 namespace com{
  namespace siemens{
   namespace ct{
    namespace exi{
     namespace api{
      namespace sax{
       class EXISource;
       class SAXDecoder;
      } // end namespace sax

      namespace stream{
       class EmptyLocation;
       class StAXEncoder;
      } // end namespace stream
     } // end namespace api

     namespace attributes{
      class AttributeFactory;
      class AttributeList;
      class AttributeListSchemaLess;
     } // end namespace attributes

     namespace cmd{
      class EXIficientCMD;
     } // end namespace cmd

     namespace context{
      class QNameContext;
     } // end namespace context

     namespace core{
      class EXIBodyDecoderInOrderSC;
      class EXIBodyDecoderReordered;
     } // end namespace core

     namespace datatype{
      class BinaryBase64Datatype;
      class BooleanFacetDatatype;
      namespace charset{
       class XSDBase64CharacterSet;
       class XSDDecimalCharacterSet;
       class XSDHexBinaryCharacterSet;
       class XSDStringCharacterSet;
      } // end namespace charset

      class DatetimeDatatype;
      class EnumerationDatatype;
      class ListDatatype;
      class RestrictedCharacterSetDatatype;
      namespace strings{
       class StringDecoderImpl;
       class BoundedStringDecoderImpl;
       class StringCoder;
      } // end namespace strings
     } // end namespace datatype

     class DecodingOptions;
     namespace exceptions{
      class ErrorHandler;
      class UnsupportedOption;
      class XMLParsingException;
     } // end namespace exceptions

     class EXIBodyEncoder;
     class EXIStreamDecoder;
     class FidelityOptions;
     namespace grammars{
      namespace event{
       class AbstractDatatypeEvent;
       class Attribute;
       class Characters;
       class CharactersGeneric;
       class DatatypeEvent;
       class EndDocument;
       class EntityReference;
      } // end namespace event
     } // end namespace grammars

     namespace util{
      class FragmentUtilities;
      namespace xml{
       class QNameUtilities;
      } // end namespace xml
     } // end namespace util
    } // end namespace exi
   } // end namespace ct
  } // end namespace siemens
 } // end namespace com

 namespace org{
  namespace apache{
   namespace html{
    namespace dom{
     class HTMLBaseElementImpl;
     class HTMLDirectoryElementImpl;
     class HTMLFrameElementImpl;
     class HTMLInputElementImpl;
    } // end namespace dom
   } // end namespace html

   namespace wml{
    class WMLDOMImplementation;
    class WMLIElement;
    class WMLPElement;
    class WMLTableElement;
    namespace dom{
     class WMLAccessElementImpl;
     class WMLDocumentImpl;
     class WMLIElementImpl;
    } // end namespace dom
   } // end namespace wml

   namespace xerces{
    namespace impl{
     namespace dtd{
      namespace models{
       class DFAContentModel;
      } // end namespace models
     } // end namespace dtd

     namespace dv{
      class ValidationContext;
      class XSFacets;
      namespace dtd{
       class ENTITYDatatypeValidator;
       class ListDatatypeValidator;
       class IDDatatypeValidator;
       class XML11IDDatatypeValidator;
      } // end namespace dtd

      namespace util{
       class Base64;
      } // end namespace util

      namespace xs{
       class AnyAtomicDV;
       class AnySimpleDV;
       class AnyURIDV;
       class BooleanDV;
       class DateTimeDV;
       class IDDV;
       class PrecisionDecimalDV;
       class StringDV;
       class YearDV;
       class YearMonthDurationDV;
      } // end namespace xs
     } // end namespace dv
    } // end namespace impl
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace io{
   class CharConversionException;
  } // end namespace io
 } // end namespace java

 namespace org{
  namespace apache{
   namespace xerces{
    namespace impl{
     namespace io{
      class MalformedByteSequenceException;
      class UTF16Reader;
     } // end namespace io

     namespace xs{
      namespace models{
       class XSDFACM;
      } // end namespace models

      namespace opti{
       class ElementImpl;
       class SchemaDOMImplementation;
       class SchemaDOMParser;
       class TextImpl;
      } // end namespace opti

      namespace traversers{
       class LargeContainer;
       class OneAttr;
       class SchemaContentHandler;
       class XSAnnotationInfo;
       class XSAttributeChecker;
       class XSDComplexTypeTraverser;
       class XSDSimpleTypeTraverser;
      } // end namespace traversers

      namespace util{
       class LSInputListImpl;
       class ObjectListImpl;
       class StringListImpl;
       class XIntPool;
       class XSInputSource;
       class XSObjectListImpl;
      } // end namespace util
     } // end namespace xs
    } // end namespace impl
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace parsers{
    class DocumentBuilder;
   } // end namespace parsers
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace apache{
   namespace xerces{
    namespace jaxp{
     class DocumentBuilderImpl;
    } // end namespace jaxp
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace parsers{
    class SAXParserFactory;
   } // end namespace parsers
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace apache{
   namespace xerces{
    namespace jaxp{
     class SAXParserFactoryImpl;
     class SchemaValidatorConfiguration;
     namespace datatype{
      class DatatypeFactoryImpl;
      class SerializedXMLGregorianCalendar;
     } // end namespace datatype

     namespace validation{
      class DOMDocumentHandler;
      class DOMResultAugmentor;
      class DOMValidatorHelper;
      class StAXValidatorHelper;
      class ValidatorHandlerImpl;
      class XMLSchemaFactory;
     } // end namespace validation
    } // end namespace jaxp

    namespace util{
     class SAXInputSource;
    } // end namespace util

    namespace xs{
     class XSAttributeUse;
     class XSLoader;
     class XSNotationDeclaration;
     class XSWildcard;
    } // end namespace xs
   } // end namespace xerces

   namespace xml{
    namespace serialize{
     class HTMLdtd;
    } // end namespace serialize
   } // end namespace xml
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   class XMLConstants;
   namespace datatype{
    class FactoryFinder;
   } // end namespace datatype

   namespace parsers{
    class FilePathToURI;
   } // end namespace parsers

   namespace stream{
    class XMLEventWriter;
    class XMLStreamWriter;
    namespace events{
     class EntityReference;
    } // end namespace events

    namespace util{
     class StreamReaderDelegate;
    } // end namespace util
   } // end namespace stream

   namespace transform{
    class Transformer;
    namespace dom{
     class DOMSource;
    } // end namespace dom

    namespace stream{
     class FilePathToURI;
    } // end namespace stream
   } // end namespace transform

   namespace validation{
    class SchemaFactoryFinder;
   } // end namespace validation

   namespace xpath{
    class XPathFactoryConfigurationException;
    class XPathFunctionResolver;
   } // end namespace xpath
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace w3c{
   namespace dom{
    class DOMConfiguration;
    class DOMStringList;
    class NameList;
    class UserDataHandler;
    namespace css{
     class CSSFontFaceRule;
     class CSSStyleDeclaration;
     class DocumentCSS;
    } // end namespace css

    namespace events{
     class EventListener;
    } // end namespace events

    namespace html{
     class HTMLBRElement;
     class HTMLDivElement;
     class HTMLHRElement;
     class HTMLLIElement;
     class HTMLOListElement;
     class HTMLScriptElement;
    } // end namespace html

    namespace ls{
     class LSLoadEvent;
    } // end namespace ls

    namespace ranges{
     class DocumentRange;
    } // end namespace ranges

    namespace traversal{
     class DocumentTraversal;
    } // end namespace traversal

    namespace xpath{
     class XPathExpression;
    } // end namespace xpath
   } // end namespace dom
  } // end namespace w3c

  namespace xml{
   namespace sax{
    class DocumentHandler;
    namespace ext{
     class DeclHandler;
    } // end namespace ext

    namespace helpers{
     class ParserFactory;
    } // end namespace helpers
   } // end namespace sax
  } // end namespace xml
 } // end namespace org

 namespace crcl{
  namespace utils{
   class PendantClientOuter;
   class SideViewJPanel;
   class SimulatedKinematicsSimple;
   class XpathQueryJFrame;
  } // end namespace utils
 } // end namespace crcl

 namespace rcsdesign{
  class InnerAppletRepainter;
 } // end namespace rcsdesign

 namespace rcs{
  namespace nml{
   class CMS_DATE;
   class XMLFileReader;
   class NML_ENUM_INFO;
   class PackedFormatConverter;
  } // end namespace nml
 } // end namespace rcs

 namespace diagapplet{
  namespace plotter{
   class PlotPoint;
   class PlotterCommon;
   class PlotLoader;
  } // end namespace plotter

  namespace CodeGen{
   class ChannelInfo;
  } // end namespace CodeGen
 } // end namespace diagapplet

 namespace java{
  namespace awt{
   class TextField;
  } // end namespace awt
 } // end namespace java

 namespace diagapplet{
  namespace CodeGen{
   class CodeGenTextFieldWrapper;
   class CodeGenCommonInterface;
   class Ada_Generator;
   class CodeGenCodeTextAreaInterface;
   class CodeGenTextAreaInterface;
   class CodeGenCmdLine;
   class SplitInfoToken;
   class DiagNMLMsgDict;
   class DiagNMLMsgDictCreatorInterface;
   class ByteArrayObject;
   class ModuleInfo;
  } // end namespace CodeGen

  namespace utils{
   class FastListPanelItem;
  } // end namespace utils

  class HierarchyDraw;
  class CodeFileInfo;
 } // end namespace diagapplet

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace analysis{
      namespace function{
       class Min;
       class Divide;
       class Identity;
       class Minus;
      } // end namespace function

      namespace integration{
       namespace gauss{
        class GaussIntegrator;
        class LegendreHighPrecisionRuleFactory;
       } // end namespace gauss

       class RombergIntegrator;
       class TrapezoidIntegrator;
       class SimpsonIntegrator;
      } // end namespace integration

      namespace solvers{
       class MullerSolver;
       class BracketingNthOrderBrentSolver;
       class BisectionSolver;
       class IllinoisSolver;
       class BracketedUnivariateSolver;
       class RegulaFalsiSolver;
       class UnivariateSolver;
       class PolynomialSolver;
      } // end namespace solvers

      namespace interpolation{
       class PiecewiseBicubicSplineInterpolator;
       class MicrosphereInterpolatingFunction;
      } // end namespace interpolation

      class UnivariateVectorFunction;
      class DifferentiableUnivariateFunction;
     } // end namespace analysis

     namespace ode{
      namespace nonstiff{
       class GraggBulirschStoerStepInterpolator;
      } // end namespace nonstiff

      namespace events{
       class EventHandler;
      } // end namespace events

      namespace sampling{
       class FixedStepHandler;
      } // end namespace sampling
     } // end namespace ode

     namespace ml{
      namespace neuralnet{
       namespace sofm{
        class LearningFactorFunctionFactory;
       } // end namespace sofm
      } // end namespace neuralnet
     } // end namespace ml

     namespace stat{
      namespace descriptive{
       namespace rank{
        class PSquarePercentile;
       } // end namespace rank

       namespace moment{
        class SemiVariance;
        class Mean;
       } // end namespace moment

       class AggregateSummaryStatistics;
       class SynchronizedMultivariateSummaryStatistics;
      } // end namespace descriptive

      namespace clustering{
       class EuclideanDoublePoint;
       class KMeansPlusPlusClusterer;
      } // end namespace clustering

      namespace correlation{
       class StorelessCovariance;
       class PearsonsCorrelation;
      } // end namespace correlation

      namespace ranking{
       class RankingAlgorithm;
      } // end namespace ranking

      namespace interval{
       class NormalApproximationInterval;
       class ClopperPearsonInterval;
      } // end namespace interval
     } // end namespace stat

     namespace optim{
      namespace linear{
       class LinearConstraint;
      } // end namespace linear

      class PointValuePair;
     } // end namespace optim

     namespace fraction{
      class Fraction;
     } // end namespace fraction

     namespace distribution{
      class ParetoDistribution;
      class ExponentialDistribution;
      class GeometricDistribution;
      class BetaDistribution;
      class PascalDistribution;
      class NormalDistribution;
      class SaddlePointExpansion;
      class ZipfDistribution;
      class EnumeratedDistribution;
      class WeibullDistribution;
      class KolmogorovSmirnovDistribution;
      class FDistribution;
      class BinomialDistribution;
      class RealDistribution;
     } // end namespace distribution

     namespace transform{
      class FastCosineTransformer;
     } // end namespace transform

     namespace geometry{
      namespace partitioning{
       class BoundarySizeVisitor;
      } // end namespace partitioning

      class Vector;
     } // end namespace geometry

     namespace linear{
      class TriDiagonalTransformer;
      class DefaultIterativeLinearSolverEvent;
      class HessenbergTransformer;
      class SparseFieldVector;
      class BiDiagonalTransformer;
      class SingularValueDecomposition;
      class MatrixUtils;
      class NonPositiveDefiniteMatrixException;
      class FieldVectorChangingVisitor;
      class FieldVectorPreservingVisitor;
      class SparseFieldMatrix;
      class SparseRealVector;
      class OpenMapRealVector;
      class SparseRealMatrix;
      class OpenMapRealMatrix;
      class ArrayRealVector;
     } // end namespace linear

     namespace exception{
      namespace util{
       class ExceptionContext;
      } // end namespace util
     } // end namespace exception
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace crcl{
  namespace base{
   class InitCanonType;
   class JointStatusesType;
   class JointStatusType;
   class MoveThroughToType;
  } // end namespace base
 } // end namespace crcl

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace comparator{
      class DirectoryFileComparator;
     } // end namespace comparator

     namespace filefilter{
      class CanReadFileFilter;
      class OrFileFilter;
     } // end namespace filefilter

     class FilenameUtils;
     namespace input{
      class AutoCloseInputStream;
      class BOMInputStream;
      class BrokenInputStream;
      class CharSequenceInputStream;
      class ClosedInputStream;
      class CountingInputStream;
      class DemuxInputStream;
      class NullInputStream;
      class NullReader;
     } // end namespace input
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace io{
   class FilterReader;
  } // end namespace io
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace input{
      class ProxyReader;
      class TaggedInputStream;
      class TailerListener;
      class TailerListenerAdapter;
      class TeeInputStream;
      class XmlStreamReaderException;
     } // end namespace input

     class IOCase;
     class IOUtils;
     namespace output{
      class NullOutputStream;
      class NullWriter;
      class StringBuilderWriter;
      class TeeOutputStream;
     } // end namespace output
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace com{
  namespace siemens{
   namespace ct{
    namespace exi{
     namespace api{
      namespace dom{
       class DocumentFragmentBuilder;
      } // end namespace dom
     } // end namespace api

     namespace io{
      namespace channel{
       class ByteDecoderChannel;
       class EncoderChannel;
      } // end namespace channel
     } // end namespace io

     namespace types{
      class BuiltIn;
      class TypeCoder;
     } // end namespace types

     namespace util{
      class NoEntityResolver;
     } // end namespace util
    } // end namespace exi
   } // end namespace ct
  } // end namespace siemens
 } // end namespace com

 namespace org{
  namespace apache{
   namespace html{
    namespace dom{
     class HTMLHeadElementImpl;
     class HTMLLabelElementImpl;
    } // end namespace dom
   } // end namespace html

   namespace wml{
    class WMLDoElement;
    class WMLImgElement;
    class WMLPostfieldElement;
    class WMLTdElement;
    namespace dom{
     class WMLAnchorElementImpl;
     class WMLBElementImpl;
     class WMLBigElementImpl;
    } // end namespace dom
   } // end namespace wml

   namespace xerces{
    namespace impl{
     namespace dtd{
      class XMLDTDValidatorFilter;
      class XMLEntityDecl;
      class XMLSimpleType;
      namespace models{
       class CMBinOp;
       class CMUniOp;
       class SimpleContentModel;
      } // end namespace models
     } // end namespace dtd

     namespace dv{
      class ValidatedInfo;
      namespace dtd{
       class NOTATIONDatatypeValidator;
       class XML11IDREFDatatypeValidator;
      } // end namespace dtd

      namespace util{
       class ByteListImpl;
      } // end namespace util

      namespace xs{
       class DateDV;
       class DayTimeDurationDV;
       class DoubleDV;
       class HexBinaryDV;
       class IDREFDV;
       class MonthDayDV;
       class SchemaDVFactoryImpl;
       class TimeDV;
       class XSSimpleTypeDecl;
      } // end namespace xs
     } // end namespace dv
    } // end namespace impl

    namespace jaxp{
     namespace validation{
      class XSGrammarPoolContainer;
     } // end namespace validation
    } // end namespace jaxp

    namespace parsers{
     class DOMParserImpl;
     class DOMASBuilderImpl;
     class NonValidatingConfiguration;
     class SAXParser;
     class SecuritySupport;
     class XML11Configurable;
     class XMLDocumentParser;
     class XMLGrammarCachingConfiguration;
     class XMLGrammarPreparser;
    } // end namespace parsers

    namespace stax{
     class EmptyLocation;
     namespace events{
      class CommentImpl;
      class EndDocumentImpl;
      class EntityReferenceImpl;
      class ProcessingInstructionImpl;
      class StartElementImpl;
     } // end namespace events
    } // end namespace stax

    namespace util{
     class DOMEntityResolverWrapper;
     class DOMInputSource;
     class DatatypeMessageFormatter;
     class EncodingMap;
     class StAXInputSource;
    } // end namespace util

    namespace xs{
     class XSFacet;
     class XSNamedMap;
     class XSTerm;
     namespace datatypes{
      class XSDecimal;
      class XSDouble;
     } // end namespace datatypes
    } // end namespace xs
   } // end namespace xerces

   namespace xml{
    namespace serialize{
     class EncodingInfo;
     class Encodings;
     class SerializerFactoryImpl;
     class TextSerializer;
    } // end namespace serialize
   } // end namespace xml
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace datatype{
    class DatatypeConfigurationException;
   } // end namespace datatype

   namespace stream{
    class SecuritySupport;
    class XMLResolver;
    namespace events{
     class DTD;
     class StartDocument;
    } // end namespace events
   } // end namespace stream

   namespace transform{
    namespace stream{
     class StreamSource;
    } // end namespace stream
   } // end namespace transform

   namespace xpath{
    class XPathConstants;
    class XPathExpression;
   } // end namespace xpath
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace w3c{
   namespace dom{
    class Comment;
    class DOMLocator;
    class EntityReference;
    namespace css{
     class CSS2Properties;
     class RGBColor;
    } // end namespace css

    namespace events{
     class MouseEvent;
    } // end namespace events

    namespace html{
     class HTMLBaseFontElement;
     class HTMLElement;
     class HTMLHeadingElement;
     class HTMLLegendElement;
     class HTMLSelectElement;
     class HTMLTextAreaElement;
    } // end namespace html

    namespace ls{
     class LSParser;
     class LSParserFilter;
    } // end namespace ls

    namespace stylesheets{
     class DocumentStyle;
    } // end namespace stylesheets

    namespace traversal{
     class TreeWalker;
    } // end namespace traversal

    namespace views{
     class AbstractView;
    } // end namespace views
   } // end namespace dom
  } // end namespace w3c

  namespace xml{
   namespace sax{
    class AttributeList;
    class InputSource;
    class XMLReader;
    namespace ext{
     class Attributes2;
    } // end namespace ext

    namespace helpers{
     class AttributeListImpl;
     class ParserAdapter;
    } // end namespace helpers
   } // end namespace sax
  } // end namespace xml
 } // end namespace org

 namespace crcl{
  namespace utils{
   class TestInstance;
   class SimServer;
   class CmdLineSimServer;
   class AnnotatedPose;
   class CRCLSocket;
  } // end namespace utils
 } // end namespace crcl

 namespace rcsdesign{
  class rcsDesignWriterInfo;
  class AlphabetizedList;
  class rcsdesignMainLoopInfo;
  class rcsDesignWriter;
 } // end namespace rcsdesign

 namespace rcs{
  namespace posemath{
   class Posemath;
  } // end namespace posemath

  namespace utils{
   class URL_and_FileLoader;
  } // end namespace utils
 } // end namespace rcs

 namespace diagapplet{
  class diag_common;
  namespace CodeGen{
   class DiagNMLMsgDictInterface;
   class EnumTypeInfo;
  } // end namespace CodeGen

  class JPaintablePanel;
  class CodeDisplayPanel;
 } // end namespace diagapplet

 namespace org{
  namespace apache{
   namespace commons{
    namespace math3{
     namespace analysis{
      namespace differentiation{
       class UnivariateDifferentiableVectorFunction;
       class UnivariateFunctionDifferentiator;
      } // end namespace differentiation

      namespace function{
       class Sigmoid;
       class Atan2;
       class Sqrt;
       class StepFunction;
       class Power;
       class Gaussian;
       class Tan;
       class Floor;
       class Acosh;
       class Cos;
       class Add;
       class Atan;
       class Asinh;
      } // end namespace function

      namespace integration{
       namespace gauss{
        class GaussIntegratorFactory;
        class SymmetricGaussIntegrator;
       } // end namespace gauss
      } // end namespace integration

      namespace solvers{
       class MullerSolver2;
      } // end namespace solvers

      namespace interpolation{
       class LoessInterpolator;
      } // end namespace interpolation

      class MultivariateMatrixFunction;
      class MultivariateFunction;
     } // end namespace analysis

     namespace ode{
      namespace nonstiff{
       class ClassicalRungeKuttaStepInterpolator;
       class DormandPrince54StepInterpolator;
       class AdamsBashforthIntegrator;
       class EmbeddedRungeKuttaIntegrator;
       class HighamHall54Integrator;
       class DormandPrince853Integrator;
       class DormandPrince54Integrator;
       class MidpointIntegrator;
      } // end namespace nonstiff

      class ContinuousOutputModel;
      class FirstOrderIntegrator;
      class EquationsMapper;
      class ExpandableStatefulODE;
      class UnknownParameterException;
      class AbstractParameterizable;
      class ParameterConfiguration;
      class SecondOrderIntegrator;
      class ParameterJacobianWrapper;
      class FirstOrderConverter;
     } // end namespace ode

     namespace optimization{
      namespace direct{
       class AbstractSimplex;
       class PowellOptimizer;
       class NelderMeadSimplex;
       class MultivariateFunctionMappingAdapter;
       class MultiDirectionalSimplex;
      } // end namespace direct

      namespace univariate{
       class SimpleUnivariateValueChecker;
       class BaseUnivariateOptimizer;
       class BrentOptimizer;
       class UnivariateOptimizer;
      } // end namespace univariate

      class SimpleValueChecker;
      class MultivariateMultiStartOptimizer;
      class LeastSquaresConverter;
      class Weight;
      class SimpleVectorValueChecker;
      class InitialGuess;
      class MultivariateDifferentiableMultiStartOptimizer;
      class SimpleBounds;
     } // end namespace optimization

     namespace ml{
      namespace neuralnet{
       namespace sofm{
        namespace util{
         class ExponentialDecayFunction;
        } // end namespace util

        class NeighbourhoodSizeFunctionFactory;
       } // end namespace sofm
      } // end namespace neuralnet
     } // end namespace ml

     namespace stat{
      namespace descriptive{
       namespace moment{
        class VectorialMean;
        class GeometricMean;
       } // end namespace moment
      } // end namespace descriptive
     } // end namespace stat

     namespace complex{
      class ComplexFormat;
     } // end namespace complex

     namespace dfp{
      class DfpField;
     } // end namespace dfp

     namespace special{
      class BesselJ;
      class Erf;
     } // end namespace special

     namespace primes{
      class SmallPrimes;
     } // end namespace primes

     namespace optim{
      namespace nonlinear{
       namespace vector{
        class Weight;
        class MultiStartMultivariateVectorOptimizer;
       } // end namespace vector
      } // end namespace nonlinear

      namespace linear{
       class NonNegativeConstraint;
       class NoFeasibleSolutionException;
       class LinearObjectiveFunction;
      } // end namespace linear
     } // end namespace optim

     namespace fraction{
      class FractionField;
     } // end namespace fraction

     namespace geometry{
      namespace enclosing{
       class Encloser;
      } // end namespace enclosing

      namespace euclidean{
       namespace threed{
        class OutlineExtractor;
        class SubPlane;
        class SphereGenerator;
        class Segment;
        class Line;
        class CardanEulerSingularityException;
        class RotationOrder;
        class NotARotationMatrixException;
        class FieldVector3D;
       } // end namespace threed

       namespace twod{
        namespace hull{
         class AbstractConvexHullGenerator2D;
         class MonotoneChain;
         class AklToussaintHeuristic;
         class ConvexHullGenerator2D;
         class ConvexHull2D;
        } // end namespace hull

        class DiskGenerator;
       } // end namespace twod
      } // end namespace euclidean
     } // end namespace geometry

     namespace exception{
      class MathRuntimeException;
      class InsufficientDataException;
      class MathParseException;
     } // end namespace exception
    } // end namespace math3
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace crcl{
  namespace base{
   class VacuumGripperStatusType;
   class GetStatusType;
   class RotSpeedAbsoluteType;
  } // end namespace base
 } // end namespace crcl

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace comparator{
      class DefaultFileComparator;
     } // end namespace comparator

     class FileCleaningTracker;
     namespace filefilter{
      class ConditionalFileFilter;
      class IOFileFilter;
      class SizeFileFilter;
     } // end namespace filefilter

     namespace input{
      class CharSequenceReader;
     } // end namespace input
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace java{
  namespace io{
   class ObjectInputStream;
  } // end namespace io
 } // end namespace java

 namespace org{
  namespace apache{
   namespace commons{
    namespace io{
     namespace input{
      class ClassLoaderObjectInputStream;
      class CloseShieldInputStream;
     } // end namespace input

     namespace output{
      class XmlStreamWriter;
     } // end namespace output
    } // end namespace io
   } // end namespace commons
  } // end namespace apache
 } // end namespace org

 namespace com{
  namespace siemens{
   namespace ct{
    namespace exi{
     namespace types{
      class LexicalTypeDecoder;
      class LexicalTypeEncoder;
      class TypeEncoder;
     } // end namespace types

     namespace util{
      namespace sort{
       class LexicographicSort;
      } // end namespace sort

      namespace xml{
       class XMLWhitespace;
      } // end namespace xml
     } // end namespace util
    } // end namespace exi
   } // end namespace ct
  } // end namespace siemens
 } // end namespace com

 namespace org{
  namespace apache{
   namespace html{
    namespace dom{
     class HTMLBaseFontElementImpl;
     class HTMLDivElementImpl;
     class HTMLFrameSetElementImpl;
     class HTMLHRElementImpl;
     class HTMLLIElementImpl;
     class HTMLObjectElementImpl;
    } // end namespace dom
   } // end namespace html

   namespace wml{
    class WMLMetaElement;
    class WMLRefreshElement;
    class WMLTimerElement;
    namespace dom{
     class WMLGoElementImpl;
    } // end namespace dom
   } // end namespace wml

   namespace xerces{
    namespace impl{
     class XMLEntityManager;
     namespace xpath{
      class XPathException;
      namespace regex{
       class BMPattern;
      } // end namespace regex
     } // end namespace xpath

     namespace xs{
      class PSVIErrorList;
      class SchemaNamespaceSupport;
      class SubstitutionGroupHandler;
      class XMLSchemaException;
      class XMLSchemaValidator;
      namespace identity{
       class FieldActivator;
       class KeyRef;
       class Selector;
       class UniqueOrKey;
      } // end namespace identity

      namespace models{
       class CMNodeFactory;
       class XSCMBinOp;
       class XSCMUniOp;
      } // end namespace models
     } // end namespace xs
    } // end namespace impl

    namespace jaxp{
     namespace validation{
      class SoftReferenceGrammarPool;
      class StAXStreamResultBuilder;
      class Util;
      class ValidatorHelper;
      class ValidatorImpl;
      class XMLSchema;
     } // end namespace validation
    } // end namespace jaxp

    namespace util{
     class SAXLocatorWrapper;
     class SAXMessageFormatter;
     class SecurityManager;
     class SymbolTable;
     class ShadowedSymbolTable;
     class SoftReferenceSymbolTable;
     class StAXLocationWrapper;
     class SymbolHash;
     class SynchronizedSymbolTable;
     class URI;
     class XML11Char;
     class XMLAttributesImpl;
     class XMLChar;
     class XMLEntityDescriptionImpl;
     class XMLErrorCode;
     class XMLLocatorWrapper;
     class XMLStringBuffer;
     class XMLSymbols;
    } // end namespace util

    namespace xinclude{
     class ObjectFactory;
     class SecuritySupport;
     class XInclude11TextReader;
     class XIncludeHandler;
    } // end namespace xinclude

    namespace xni{
     class XMLResourceIdentifier;
     class XNIException;
     namespace grammars{
      class XMLGrammarDescription;
      class XMLSchemaDescription;
     } // end namespace grammars

     namespace parser{
      class XMLConfigurationException;
      class XMLDTDScanner;
      class XMLEntityResolver;
      class XMLParseException;
     } // end namespace parser
    } // end namespace xni

    namespace xpointer{
     class ElementSchemePointer;
     class XPointerHandler;
    } // end namespace xpointer

    namespace xs{
     class ShortList;
     class XSAttributeDeclaration;
     class XSImplementation;
     class XSNamespaceItemList;
     class XSValue;
     namespace datatypes{
      class XSQName;
     } // end namespace datatypes
    } // end namespace xs
   } // end namespace xerces
  } // end namespace apache
 } // end namespace org

 namespace javax{
  namespace xml{
   namespace datatype{
    class DatatypeConstants;
   } // end namespace datatype

   namespace parsers{
    class FactoryConfigurationError;
   } // end namespace parsers

   namespace stream{
    class EventFilter;
    class XMLInputFactory;
    namespace events{
     class Attribute;
     class Namespace;
    } // end namespace events

    namespace util{
     class XMLEventAllocator;
    } // end namespace util
   } // end namespace stream

   namespace transform{
    class Templates;
    namespace dom{
     class DOMResult;
    } // end namespace dom

    namespace stax{
     class StAXSource;
    } // end namespace stax
   } // end namespace transform

   namespace xpath{
    class SecuritySupport;
    class XPathVariableResolver;
   } // end namespace xpath
  } // end namespace xml
 } // end namespace javax

 namespace org{
  namespace w3c{
   namespace dom{
    class DOMError;
    class Document;
    class NamedNodeMap;
    namespace css{
     class CSSMediaRule;
     class CSSStyleSheet;
     class CSSUnknownRule;
     class Rect;
    } // end namespace css

    namespace events{
     class MutationEvent;
    } // end namespace events

    namespace html{
     class HTMLBodyElement;
     class HTMLFieldSetElement;
     class HTMLHtmlElement;
     class HTMLLinkElement;
     class HTMLOptionElement;
     class HTMLTableCaptionElement;
     class HTMLUListElement;
    } // end namespace html

    namespace ls{
     class LSProgressEvent;
    } // end namespace ls

    namespace stylesheets{
     class LinkStyle;
    } // end namespace stylesheets

    namespace xpath{
     class XPathResult;
    } // end namespace xpath
   } // end namespace dom
  } // end namespace w3c

  namespace xml{
   namespace sax{
    class HandlerBase;
    class XMLFilter;
    namespace ext{
     class Locator2;
    } // end namespace ext

    namespace helpers{
     class NewInstance;
     class SecuritySupport;
    } // end namespace helpers
   } // end namespace sax
  } // end namespace xml
 } // end namespace org

 namespace crcl{
  namespace utils{
   class PendantClient;
   class CmdLineClient;
   class CRCLSocketExample;
   class PendantClientInner;
  } // end namespace utils
 } // end namespace crcl

 namespace java{
  namespace util{
   class AbstractSequentialList;
   class LinkedList;
  } // end namespace util

  namespace io{
   class File;
  } // end namespace io
 } // end namespace java

 namespace javax{
  namespace swing{
   namespace text{
    class Style;
   } // end namespace text
  } // end namespace swing
 } // end namespace javax

 namespace java{
  namespace awt{
   class AWTEvent;
   namespace event{
    class ActionEvent;
   } // end namespace event

   namespace geom{
    class Dimension2D;
   } // end namespace geom

   class Dimension;
  } // end namespace awt

  namespace util{
   class List;
  } // end namespace util

  namespace awt{
   class Image;
   namespace image{
    class BufferedImage;
   } // end namespace image
  } // end namespace awt
 } // end namespace java

 namespace javax{
  namespace swing{
   class JScrollBar;
  } // end namespace swing
 } // end namespace javax

 namespace java{
  namespace awt{
   class Scrollbar;
  } // end namespace awt
 } // end namespace java

 namespace javax{
  namespace swing{
   class SwingWorker;
  } // end namespace swing
 } // end namespace javax

 namespace java{
  namespace lang{
   class Runnable;
  } // end namespace lang

  namespace awt{
   class Graphics;
  } // end namespace awt

  namespace util{
   class Dictionary;
   class Hashtable;
  } // end namespace util

  namespace lang{
   class Long;
  } // end namespace lang

  namespace util{
   class Vector;
  } // end namespace util

  namespace io{
   class ObjectOutput;
   class ObjectInput;
  } // end namespace io

  namespace util{
   class Collection;
   class Comparator;
  } // end namespace util

  namespace lang{
   class Iterable;
  } // end namespace lang

  namespace util{
   class Iterator;
  } // end namespace util

  namespace net{
   class URL;
  } // end namespace net

  namespace util{
   class Locale;
  } // end namespace util

  namespace lang{
   class AbstractStringBuilder;
   class StringBuffer;
  } // end namespace lang

  namespace text{
   class FieldPosition;
   class ParsePosition;
  } // end namespace text

  namespace util{
   class Set;
  } // end namespace util

  namespace math{
   class BigDecimal;
  } // end namespace math

  namespace util{
   class Enumeration;
  } // end namespace util

  namespace lang{
   class Boolean;
   class ClassLoader;
  } // end namespace lang

  namespace awt{
   namespace event{
    class ItemEvent;
    class ComponentEvent;
    class WindowEvent;
   } // end namespace event
  } // end namespace awt
 } // end namespace java

 namespace javax{
  namespace xml{
   namespace bind{
    class JAXBElement;
   } // end namespace bind
  } // end namespace xml
 } // end namespace javax

 namespace java{
  namespace io{
   class FilenameFilter;
   class FileFilter;
  } // end namespace io

  namespace util{
   class Date;
  } // end namespace util

  namespace lang{
   class Thread;
  } // end namespace lang

  namespace awt{
   class Color;
  } // end namespace awt
 } // end namespace java

 namespace javax{
  namespace swing{
   class JTable;
  } // end namespace swing
 } // end namespace javax

 namespace java{
  namespace awt{
   namespace event{
    class ActionListener;
    class KeyListener;
    class InputEvent;
    class MouseEvent;
   } // end namespace event
  } // end namespace awt

  namespace io{
   class FileOutputStream;
  } // end namespace io

  namespace awt{
   namespace event{
    class KeyEvent;
   } // end namespace event
  } // end namespace awt
 } // end namespace java

 namespace javafx{
  namespace stage{
   class Window;
   class Stage;
  } // end namespace stage
 } // end namespace javafx

 namespace java{
  namespace util{
   class ResourceBundle;
  } // end namespace util

  namespace math{
   class BigInteger;
  } // end namespace math

  namespace nio{
   namespace charset{
    class Charset;
   } // end namespace charset
  } // end namespace nio

  namespace util{
   class Calendar;
   class ListIterator;
   class GregorianCalendar;
   class TimeZone;
  } // end namespace util

  namespace io{
   class PrintWriter;
   class PrintStream;
  } // end namespace io

  namespace awt{
   namespace event{
    class AdjustmentEvent;
   } // end namespace event
  } // end namespace awt
 } // end namespace java

 namespace javax{
  namespace swing{
   namespace event{
    class ListSelectionListener;
   } // end namespace event

   namespace table{
    class TableCellEditor;
   } // end namespace table
  } // end namespace swing
 } // end namespace javax

 namespace java{
  namespace awt{
   namespace event{
    class MouseListener;
    class MouseMotionListener;
   } // end namespace event

   namespace geom{
    class RectangularShape;
    class Rectangle2D;
   } // end namespace geom

   class Rectangle;
  } // end namespace awt

  namespace beans{
   class PropertyChangeListener;
  } // end namespace beans
 } // end namespace java

 namespace javafx{
  namespace scene{
   namespace transform{
    class Transform;
    class Scale;
    class Translate;
   } // end namespace transform

   class Node;
   class SubScene;
   class Scene;
   class Parent;
   namespace transform{
    class Rotate;
   } // end namespace transform
  } // end namespace scene
 } // end namespace javafx

 namespace java{
  namespace util{
   class HashMap;
  } // end namespace util
 } // end namespace java

 namespace javafx{
  namespace event{
   class Event;
  } // end namespace event

  namespace scene{
   namespace input{
    class InputEvent;
    class MouseEvent;
   } // end namespace input
  } // end namespace scene
 } // end namespace javafx

 namespace java{
  namespace util{
   namespace stream{
    class Stream;
   } // end namespace stream

   namespace function{
    class ToDoubleFunction;
   } // end namespace function
  } // end namespace util

  namespace lang{
   class Comparable;
  } // end namespace lang

  namespace io{
   class FileInputStream;
  } // end namespace io

  namespace util{
   namespace zip{
    class Checksum;
   } // end namespace zip
  } // end namespace util

  namespace lang{
   class CharSequence;
  } // end namespace lang

  namespace util{
   namespace concurrent{
    class ThreadFactory;
   } // end namespace concurrent
  } // end namespace util

  namespace lang{
   class Double;
   class Float;
  } // end namespace lang

  namespace util{
   namespace function{
    class Predicate;
   } // end namespace function
  } // end namespace util
 } // end namespace java

 namespace javax{
  namespace swing{
   namespace text{
    class AbstractDocument;
    class DefaultStyledDocument;
   } // end namespace text
  } // end namespace swing
 } // end namespace javax

 namespace java{
  namespace awt{
   namespace event{
    class TextEvent;
   } // end namespace event
  } // end namespace awt

  namespace net{
   class DatagramPacket;
  } // end namespace net
 } // end namespace java

 namespace javax{
  namespace swing{
   class AbstractListModel;
   class DefaultComboBoxModel;
  } // end namespace swing
 } // end namespace javax

 namespace java{
  namespace util{
   class ArrayList;
  } // end namespace util

  namespace awt{
   namespace event{
    class ItemListener;
   } // end namespace event

   namespace geom{
    class AffineTransform;
   } // end namespace geom
  } // end namespace awt

  namespace io{
   class Serializable;
  } // end namespace io
 } // end namespace java

 namespace javax{
  namespace swing{
   class ProgressMonitor;
  } // end namespace swing
 } // end namespace javax

 namespace java{
  namespace awt{
   namespace print{
    class PageFormat;
   } // end namespace print
  } // end namespace awt

  namespace io{
   class ObjectOutputStream;
  } // end namespace io

  namespace nio{
   class Buffer;
   class CharBuffer;
  } // end namespace nio

  namespace io{
   class BufferedReader;
  } // end namespace io

  namespace net{
   class Socket;
  } // end namespace net

  namespace nio{
   namespace channels{
    class Selector;
   } // end namespace channels
  } // end namespace nio

  namespace net{
   class ServerSocket;
  } // end namespace net

  namespace io{
   class Closeable;
  } // end namespace io

  namespace net{
   class URI;
   class URLConnection;
  } // end namespace net

  namespace lang{
   class StringBuilder;
  } // end namespace lang

  namespace text{
   class CharacterIterator;
  } // end namespace text

  namespace net{
   class InetAddress;
  } // end namespace net

  namespace util{
   namespace function{
    class UnaryOperator;
   } // end namespace function

   class Optional;
   namespace function{
    class Function;
   } // end namespace function
  } // end namespace util
 } // end namespace java



// end namespace crclj
}

// end #ifndef crclj_fwd_h
#endif

