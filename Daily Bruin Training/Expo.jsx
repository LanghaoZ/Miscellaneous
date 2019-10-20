
function Loader() {
    return  (<div className='loader'>
        <div className='loaderA'></div>
        <div className='loaderB'></div>
        <div className='loaderC'></div>
      </div>)
}
const URL = 'https://api.metro.net/agencies/lametro-rail/routes/806/stops/80134/predictions/'
class App extends React.Component {
  constructor(props) {
      super(props)
    this.state = {dtla: [], sm: []}
  }
  
  async componentDidMount() {
      const resp = await fetch(URL)
      const data = await resp.json()
        const sm = []
      const dtla = []
      data.items.forEach(item => {
        if(item.run_id === '806_0_var0') {
          dtla.push(item.minutes)
        } else {
          sm.push(item.minutes)
        }
     this.setState(state => ({
             ...state,
        sm,
        dtla,
     }))
  })
  }
  
  render() {
      return <div className='center-wrapper'>
    <header>
      <div className='icon icon--expo'>E</div>
      <h1>Expo Line Tracker</h1>
    </header>
    <main>
      <h2>Westwood Station</h2>
      <section>
        <h3>Santa Monica</h3>
        <ol class='times'>
            {this.state.sm.map((el, i) => 
              <li key={i}>{el}</li>
          )}
        </ol>
      </section>
      <section>
        <h3>Downtown Los Angeles</h3>
        <ol id='sm-times' class='times'>
            {this.state.dtla.map((el, i) =>
              <li key={i}>{el}</li>
          )}
        </ol>
      </section>
    </main>
    <footer>
      <div id='refreshed'>Refreshed 10s ago</div>
      <Loader />
    </footer>
  </div>
  }
}
ReactDOM.render(<App />, document.querySelector("#app"))